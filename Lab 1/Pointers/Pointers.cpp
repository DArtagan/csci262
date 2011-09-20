/******************************************************************************/
// William Weiskopf
// August 29, 2011
// A
//
// Review C++ syntax and learn the assert command
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#define NDEBUG
#include <cassert>
using namespace std;

int main()
{
	int value = 0;
	cout << "Please enter a value between 1 and 9: ";
	cin >> value;

	assert(value != 0);
	// 1. WHAT HAPPENS WHEN YOU ENTER A VALUE OF 0?
	/* The command prompt says that a assertion failed and gives the file location and line number of the assertion which failed.
	Also, a prompt is displayed by "Microsoft Visual C++ Debug Library" saying that there was a debug error.  Hitting "Retry" makes Visual Studio generate a break point.
	*/


	cout << "Decimal result of 1/" << value << " is " << value << endl;
	// 2. WHY DOES THE ABOVE OUTPUT STATEMENT ALWAYS RESULT IN A 0?
	/* The above always results in a zero because value was declared as and integer, and an operation is being done between it and another integer.
	If value was declared as a double, then the resultant would be stored as a double.  But since value was an integer, then the resultant became an integer (with everything being dropped after the decimal).
	*/


	int *ptr;
	ptr = new int;
	*ptr = 5;
	cout << *ptr << endl;

	//ptr = NULL;
	// 3. IS THIS LINE A MEMORY LEAK OR DANGLING POINTER?
	/* memory leak 
	*/


	//assert(ptr != NULL);

	cout << *ptr << endl; 
	// 4. WHAT HAPPENS WITH THE ABOVE OUTPUT STATEMENT?
	/* the * operator dereferences ptr.  When that happens it is found that position null does not belong to this program and that accessing it creates a violation.  
	*/


	delete ptr;
	cout << *ptr << endl; 
	// 5. WHAT HAPPENS WITH THE ABOVE OUTPUT STATEMENT? IS THIS MEMORY LEAK OR DANGLING POINTER?
	/* This is a dangling pointer.  
	The * operator is trying to dereference ptr, but the memory that ptr pointed to no longer belongs to this program and so a trash value is given. 
	*/


	double **dptr;

	dptr = new double*[5];
	for (int i = 0; i < 5; i++)
		dptr[i] = new double[3]; 

	// 6. HOW MANY ROWS IN dptr? 
	/* 5
	*/


	// 7. HOW MANY COLUMNS IN EACH ROW? 
	/* 3
	*/


	// Notice that we can treat this as a normal 2D array! No * Needed.
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++)
			dptr[i][j] = 1.5;

	// WRITE LINES OF CODE HERE TO DELETE ALL THE SPACE ALLOCATED FOR dptr
	for (int j = 0; j < 5; j++) {
		delete[] dptr[j];
	}
	delete[] dptr;

    // Pause and exit the program
    system("Pause");
    return 0;
}