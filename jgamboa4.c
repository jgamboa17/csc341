/*
 * Jonathan Gamboa
 * CSC 341
 * 09/26/2024
 * jgamboa4.c
 */

#include <stdio.h>
#include <stdlib.h>

int x;
int y = 15;

int main(int argc, char *argv[]){
	int i;
	int *value;
	value = (int *)malloc(sizeof(int)*5);
	for(i = 0; i < 5; i++)
		value[i] = i;
	
	printf("The memory address of argc is: %p \n", &argc);
	printf("The memeory address of the stack variable j is : %p \n", &i);
	printf("The memory address of the heap  variable value is %p \n", &value);
	printf("The memory address of the uninitialize data of x is: %p \n",&x);
        printf("The memory address of the initialized data of y: %p \n", &y);

	return EXIT_SUCCESS;
}
