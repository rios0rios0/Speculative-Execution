//
// Created by rios0rios0 on 08/03/19.
//

#include <stdint.h>
#include <stdio.h>
#include <zconf.h>
#include <stdbool.h>

//The secret information on code (it's not matter)
char *secret_info = "Secret information on code.";
//Relative array, to query some address (arbitrary size)
int address_array[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
//Target array (1MB [131072 * 2], when int is a 4 bytes), for simulate conditional branch
int target_array[262144];

int main(int argc, char **argv) {
	//Getting a external input (from user, for example)
	int input_index = 0;
	//Temporary variable for simulate a getting of OS
	int temp;
	while (true) {
		read:
		scanf("%d", &input_index);
		//Test for generate a conditional branch
		if (sizeof(address_array) > input_index) {
			temp = target_array[address_array[input_index] * 512];
		}
		printf("vaddr %p\n", (void *) secret_info);
		printf("pid %ju\n", (uintmax_t) getpid());
		goto read;
	}
}