/*
 * Main.cpp
 *
 *  Created on: 12 Jul 2019
 *      Author: Dave
 */

#include<iostream>

using namespace std;

void show_1(const int nElements, string texts[])
{
	//This will only return the size of the pointer! not the total bytes in the array as on line 40
	//cout << sizeof(texts) << endl;
										/*
										 * By passing an array by the conventional method the value
										 * of how many elements in the array is lost which is why the
										 * total value of bytes is correctly displayed by the line of
										 * code on line 40, but NOT here on line 14.
										 *
										 * The way around that is to also pass on the number of elements
										 * as a const int in the parameters. This way we must explicitly
										 * state when calling the function how many elements are in the
										 * array.
										 */


	for(int i = 0; i < nElements ; i++)
	{
		cout << texts[i] << endl;
	}
}


/*
 * The function below works exactly the same as the one above only this time
 * we have used the syntax of pointers for the array.
 *
 * With the pointer we dont have size information of the array, only the size info of the pointer
 * which is 8 bytes (for 64 bit machines), 4 bytes (for 32 bit) because it contains a memory address.
 */
void show_2(const int nElements, string *texts)
{
	for(int i = 0; i < nElements ; i++)
	{
		cout << texts[i] << endl;
	}
}


/*
 * If we do want to retain the information about how many elements are in the array
 * we must use the syntax shown below where we reference (get address of) and also specify
 * in square brackets how many elements are in the array.
 */
void show_3(string (&texts)[3])
{
	int arrLength = sizeof(texts)/sizeof(string);

	for(int i = 0; i < arrLength; i++)
	{
		cout << texts[i] << endl;
	}
}

//string *getArr()
//{
//	// NEVER RETURN POINTERS TO LOCAL VARIBALES
//	string texts[] = {"one", "two", "three"};	// THIS IS A LOCAL VARIBALE THAT WILL GO OUT OF SCOPE
//
//
//	//return texts;	// HERE WE WILL BE TRYING TO RETURN A POINTER THAT NO LONGER EXISTS ONCE IT GOES OUT OF SCOPE
//}

char *getMemory()
{
	char *pMem = new char[100];		/*
									 * While this may look the same as above, it is not, this is
									 * actually fine and different form above in that the memory
									 * has been manually allocated by use of the 'new' operator
									 * and so it will not go out of scope or at least the memory
									 * wont be deallocated until it is manually deallocated by the
									 * use of the keyword 'delete'
									 */

	return pMem;
}

/*
 * This is a common function to write which provides a nice way to clean up memory
 */
void freeMemory(char *pMem)
{
	delete [] pMem;
}


int main()
{

	string texts[] = {"Apple", "Orange", "Banana"};

	cout << sizeof(texts) << endl;

	show_1(3, texts);
	show_2(3, texts);
	show_3(texts);

	char *pMemory = getMemory();	/*
									* These generally come in pairs as is seen here, where some memory
									* is being allocated and then the memory is being freed up.
									*/
	freeMemory(pMemory);


	return 0;
}


