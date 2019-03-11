//
// Created by rios0rios0 on 08/03/19.
//

#include <stdio.h>

int main(int argc, char **argv) {
	int malicious_index = (*argv[1] - '0');
	char secret_info[4] = {'A', 'B', 'C', 'D'};
	char target;
	//
	if (sizeof(secret_info) > malicious_index) {
		target = secret_info[malicious_index];
	}
}