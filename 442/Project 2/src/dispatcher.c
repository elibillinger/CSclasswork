#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "dispatcher.h"
#include "shell_builtins.h"
#include "parser.h"

/**
 * dispatch_external_command() - run a pipeline of commands
 *
 * @pipeline:   A "struct command" pointer representing one or more
 *              commands chained together in a pipeline.  See the
 *              documentation in parser.h for the layout of this data
 *              structure.  It is also recommended that you use the
 *              "parseview" demo program included in this project to
 *              observe the layout of this structure for a variety of
 *              inputs.
 *
 * Note: this function should not return until all commands in the
 * pipeline have completed their execution.
 *
 * Return: The return status of the last command executed in the
 * pipeline.
 */
static int dispatch_external_command(struct command *pipeline)
{
	/*
	 * Note: this is where you'll start implementing the project.
	 *
	 * It's the only function with a "TODO".  However, if you try
	 * and squeeze your entire external command logic into a
	 * single routine with no helper functions, you'll quickly
	 * find your code becomes sloppy and unmaintainable.
	 *
	 * It's up to *you* to structure your software cleanly.  Write
	 * plenty of helper functions, and even start making yourself
	 * new files if you need.
	 *
	 * For D1: you only need to support running a single command
	 * (not a chain of commands in a pipeline), with no input or
	 * output files (output to stdout only).  In other words, you
	 * may live with the assumption that the "input_file" field in
	 * the pipeline struct you are given is NULL, and that
	 * "output_type" will always be COMMAND_OUTPUT_STDOUT.
	 *
	 * For D2: you'll extend this function to support input and
	 * output files, as well as pipeline functionality.
	 *
	 * Good luck!
	 */
	if(pipeline->output_type == COMMAND_OUTPUT_PIPE){
		int pipefd[2];
		pid_t pid;
		pid_t pid2;
		int  status;
		if(pipe(pipefd) != 0){
			fprintf(stderr,"Error with pipe");
			exit(1);
		}
		pid = fork(); // fork for piping into another command
		if(pid == -1 ){
			fprintf(stderr, "Error in forking");
			exit(1);
		}else if (pid == 0){ //child for piping into another command
			if(pipeline->input_filename != NULL){
				if(access(pipeline->input_filename,R_OK) == -1){
					fprintf(stderr,"File does not exist\n");
					exit(1);
				}
				int fd = open(pipeline->input_filename,O_RDONLY, 044);
				dup2(fd,STDIN_FILENO);
				close(fd);
			}
			close(pipefd[0]);
			dup2(pipefd[1],STDOUT_FILENO);
			execvp(pipeline->argv[0],pipeline->argv);
			fprintf(stderr,"Invalid Command\n");
			exit(1);
		} else { //parent for both
			
			pid2 = fork(); // fork for recieving from preiveous command
			if(pid2 == -1){
				fprintf(stderr, "Error in forking");
				exit(1);
			} else if(pid2 == 0){ // child for recieving from preiveous command
				// output types
				if(pipeline->pipe_to->output_type==COMMAND_OUTPUT_FILE_TRUNCATE){
					int fd = open(pipeline->pipe_to->output_filename,O_CREAT|O_WRONLY|O_TRUNC, 066);
					dup2(fd,STDOUT_FILENO);
					close(fd);
				} else if (pipeline->pipe_to->output_type==COMMAND_OUTPUT_FILE_APPEND){
					int fd = open(pipeline->pipe_to->output_filename,O_CREAT|O_WRONLY| O_APPEND,066);
					dup2(fd,STDOUT_FILENO);
					close(fd);
				}
				close(pipefd[1]);
				dup2(pipefd[0],STDIN_FILENO);
				execvp(pipeline->pipe_to->argv[0],pipeline->pipe_to->argv);
				fprintf(stderr,"Invalid Command\n");
				exit(1);
			} else {
				close(pipefd[0]);
				close(pipefd[1]);
				int status2;
				int w2 = waitpid(pid2,&status2, 0);
				if(w2 ==  -1){
					fprintf(stderr,"Error with waitpid");
					exit(1);
				}
				int w = waitpid(pid,&status, 0);
				if(w ==  -1){
					fprintf(stderr,"Error with waitpid");
					exit(1);
				}
				if(WIFEXITED(status2) && WIFEXITED(status)){
					if (status2 != 0 || status != 0) {
						return 1;
					}
					return 0;	
				}
			}
		}	
		
	} else {
		int status;
		pid_t pid = fork();
		if(pid == -1){
			fprintf(stderr, "Error in forking");
			exit(1);	
		} else if (pid == 0){ //child
			// input file set if exists
			if(pipeline->input_filename != NULL){
				if(access(pipeline->input_filename,R_OK) == -1){
					fprintf(stderr,"File does not exist\n");
					exit(1);
				}
				int fd = open(pipeline->input_filename,O_RDONLY, 066);
				dup2(fd,STDIN_FILENO);
				close(fd);
			}
			// output types 
			if(pipeline->output_type==COMMAND_OUTPUT_FILE_TRUNCATE){
				int fd = open(pipeline->output_filename,O_CREAT|O_WRONLY|O_TRUNC, 066);
				dup2(fd,STDOUT_FILENO);
				close(fd);
			} else if (pipeline->output_type==COMMAND_OUTPUT_FILE_APPEND){
				int fd = open(pipeline->output_filename,O_CREAT|O_WRONLY| O_APPEND,066);
				dup2(fd,STDOUT_FILENO);
				close(fd);
			}
			execvp(pipeline->argv[0],pipeline->argv);
			fprintf(stderr,"Invalid Command\n");
			exit(1);
		} else { //parent
			int w = waitpid(pid,&status, 0);
			if(w ==  -1){
				fprintf(stderr,"Error with waitpid");
				exit(1);
			}
			if(WIFEXITED(status)){
				if (status != 0) {
					return 1;
				}
				return 0;	
			}
		}
	}
	return 0;
}

/**
 * dispatch_parsed_command() - run a command after it has been parsed
 *
 * @cmd:                The parsed command.
 * @last_rv:            The return code of the previously executed
 *                      command.
 * @shell_should_exit:  Output parameter which is set to true when the
 *                      shell is intended to exit.
 *
 * Return: the return status of the command.
 */
static int dispatch_parsed_command(struct command *cmd, int last_rv,
				   bool *shell_should_exit)
{
	/* First, try to see if it's a builtin. */
	for (size_t i = 0; builtin_commands[i].name; i++) {
		if (!strcmp(builtin_commands[i].name, cmd->argv[0])) {
			/* We found a match!  Run it. */
			return builtin_commands[i].handler(
				(const char *const *)cmd->argv, last_rv,
				shell_should_exit);
		}
	}

	/* Otherwise, it's an external command. */
	return dispatch_external_command(cmd);
}

int shell_command_dispatcher(const char *input, int last_rv,
			     bool *shell_should_exit)
{
	int rv;
	struct command *parse_result;
	enum parse_error parse_error = parse_input(input, &parse_result);

	if (parse_error) {
		fprintf(stderr, "Input parse error: %s\n",
			parse_error_str[parse_error]);
		return -1;
	}

	/* Empty line */
	if (!parse_result)
		return last_rv;

	rv = dispatch_parsed_command(parse_result, last_rv, shell_should_exit);
	free_parse_result(parse_result);
	return rv;
}
