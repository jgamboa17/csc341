/* Jonathan Gamboa
 * CSC 341
 * 10/08/24
*/

#include <stdio.h>
#include <stdlib.h>

//this is a function prototype that lets the main know a function is available at the end of the program.
int compare_and_swap(int *pointb, int expected, int new_value);
void new_compare_and_swap(int *point1, int *point2, int *expected, int *new_value);

int main(void)
{
	/*using pointers is helpful when you want to permanantely set the value of a variable
	 * using functions. Normally when variables are created or modified in functions they disapear
	 * after the function completes, with pointers you are changing a value by using it's address.
	 */

	int *pointa;
	int expected = 1;
	int newValue = 22;

	int *new_point;
	int *new_point2;
	int *point_expected;
	int *point_return;

	int swap1 = 25;
	int swap2 = 2;
	int new_expected = 13;
	int valueReturn = 7;

	new_point = &swap1;
	new_point2 = &swap2;
	point_expected = &expected; 


	//A pointer only points to the address space of another value.
	pointa = &expected;
	//pointa now points to the address space of the value expected.
	
	//to see the address stored in the pointer we print out the pointer normally as 
	//it only stores addresses.
	printf(" address stored in pointa is %p \n",pointa);
	//if we want to see if that address is the same as the variable expected
	printf(" address of variable named expected is %p \n",&expected);
	//these print statment print the same thing because we set our pointer to point to expected
	
	//If we want to see the value that the pointer is pointing to, 
	//we use the * before our pointer
	printf(" value that pointa points to is %d \n",*pointa);
	//this should be the the same as the value of expected
	printf(" value of expected is %d \n",expected);


	//when we call a separate function we may need to pass it variables
	//this function requires three variable to be passed to it
	//it also returns a value to we need to save that value after the function completes
	
	int valueReturned = compare_and_swap(pointa,expected,newValue);
	point_return = &valueReturned;

	//after the function completes it should have swapped expected with new value
	printf("expected = %d, old value which was returned is %d \n",expected,valueReturned);

	printf("\n");
	printf("First pointer = %d, Second pointer is %d \n", *new_point, *new_point2);

	new_compare_and_swap(new_point, new_point2, point_expected, point_return);
	printf("First pointer = %d, second pointer is %d \n" , *new_point, *new_point2);
	printf("New expected = %d, old value which was returned is %d \n", *point_expected, *point_return);

	return EXIT_SUCCESS;
}

int compare_and_swap(int *pointb, int expected, int new_value)
{
	//we can use the same name for expected and it will be a different variable in this function.
	
	int temp = *pointb;
	//created a temp variable to store the original value located at the pointer pointb
	
	if(*pointb == expected)
	{
		*pointb = new_value;
	}

	return temp;
}

void new_compare_and_swap(int *point1, int *point2 ,int *expected, int *result){
	int temp;
	int temp2;

	temp = *point1;
	*point1 = *point2;
	*point2 = temp;

	temp2 = *expected;
	*expected = *result;
	*result = temp2;
	
}
	
