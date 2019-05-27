#include <stdio.h>
#include <string.h>

int main(void) {
	char msg[] = {'c', 'h', 'r', 'i', 's', 't', 'o', 'p', 'h', 'e', 'r'}; /* Character array */
	char name1[] = "christopher";       /* character array */
	char *name2 = "christopher";        /* string literal */
	fgets(name2, sizeof(name2), stdin);
	printf("sizeof: size of char array msg[] \"%s\" is %d bytes!\n", msg, sizeof(msg));
	printf("strlen: size of char array msg[] \"%s\" is %d bytes!\n", msg, strlen(msg));
	printf("sizeof: size of char array name1[] \"%s\" is %d bytes!\n", name1, sizeof(name1));
	printf("strlen: size of char array name1[] \"%s\" is %d bytes!\n", name1, strlen(name1));
	printf("sizeof: size of string \"%s\" is %d bytes!\n", name2, sizeof(name2));
	printf("strlen: size of string \"%s\" is %d bytes!\n", name2, strlen(name2));
	return 0;
}