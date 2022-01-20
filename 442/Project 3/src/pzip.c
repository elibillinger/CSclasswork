#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pzip.h"
pthread_barrier_t barrier;
int chars_count;

void *count_char (void *data){
	int counts = 0;
	struct thread_data *the_data;
	the_data = (struct thread_data *) data;
	int start = the_data->start;
	int num_char = the_data->character_num;
	int char_size = the_data->characters_size;
	char *character = the_data->characters;
	struct zipped_char *local_results = malloc(sizeof(struct thread_data)*num_char);
	struct zipped_char current;
	for (int i = start; i < (start + num_char); i++){
		char letter = character[i];
		if (letter == the_data->characters[i-1] && i > start ){
			continue;
		}
		int counter = 0;
		for(int j= i; j< (start + num_char); j++){
			if(letter == the_data->characters[j] ){
				counter++;
				if(j == (char_size)-1){
					break;
				}
			} else {
				break;
			}
			
		}
		current.occurence = counter;
		current.character = letter;
		local_results[counts] = current;
		chars_count = chars_count +1;
		counts++;
		//printf("%c%d\n",letter,counter);
	}
	the_data->characters_found = counts;
	pthread_barrier_wait (&barrier);
	pthread_exit ( (void *) local_results);
}





/**
 * pzip() - zip an array of characters in parallel
 *
 * Inputs:
 * @n_threads:		   The number of threads to use in pzip
 * @input_chars:		   The input characters (a-z) to be zipped
 * @input_chars_size:	   The number of characaters in the input file
 *
 * Outputs:
 * @zipped_chars:       The array of zipped_char structs
 * @zipped_chars_count:   The total count of inserted elements into the zippedChars array.
 * @char_frequency[26]: Total number of occurences
 *
 * NOTE: All outputs are already allocated. DO NOT MALLOC or REASSIGN THEM !!!
 *
 */
void pzip(int n_threads, char *input_chars, int input_chars_size,
	  struct zipped_char *zipped_chars, int *zipped_chars_count,
	  int *char_frequency)
{
	pthread_t threads[n_threads];
	pthread_barrier_init (&barrier, NULL, n_threads);
	int rc;
	int start = 0;
	struct thread_data data[n_threads];
	for(int t = 0; t < n_threads; t++){
		data[t].characters = input_chars;
		data[t].characters_size = input_chars_size;
		data[t].character_num = input_chars_size/n_threads;
		data[t].start = start;
		rc = pthread_create(&threads[t], NULL, count_char, (void *)&data[t]);
		if (rc) {
			fprintf(stderr,"Error with pthread create");
			exit(-1);
		}
		start += data[t].character_num;
	}
	int counter = 0;
	for(int t = 0; t < n_threads; t++){
		void *result = NULL;
		rc = pthread_join(threads[t],&result);
		struct zipped_char *results =  (struct zipped_char *) result;
		for(int i = 0; i < data[t].characters_found; i++){
			zipped_chars[counter] = results[i];
			counter++;
		}
		free(result);
		if (rc) {
			fprintf(stderr,"Error with pthread join");
			exit(-1);
		}
	}
	
	*zipped_chars_count = chars_count;
	for (size_t i = 0; i < 26; i++)
	{
		char_frequency[((int)zipped_chars[i].character-97)] = zipped_chars[i].occurence;
	}
	
}
