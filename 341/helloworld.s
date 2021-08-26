  .data # declare and initialize variables
hello:  .asciiz "Hello world!" #string with null terminator
 
  .text         # code starts here
main:           # label marking the entry point of the program
  la $a0, hello # load the address of hello into $a0 (1st argument)
  li $v0, 4     # set the syscall to print the string at the address $a0
  syscall       # make the system call
 
  li $v0, 10    # set the syscall to exit
  syscall       # make the system call