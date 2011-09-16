/************************************************************/
// William Weiskopf
// August 26, 2011
// A
//
// Good question
/************************************************************/

#include <iostream>
#include <cstdlib>

#include <cassert>
using namespace std;

int main()
{
	int value = 0;
cout << "Please enter a value between 1 and 9: ";
cin >> value;

assert(value != 0);
// 1. WHAT HAPPENS WHEN YOU ENTER A VALUE OF 0?


cout << "Decimal result of 1/" << value << " is " << 1/value << endl;
// 2. WHY DOES THE ABOVE OUTPUT STATEMENT ALWAYS RESULT IN A 0?

int *ptr;
ptr = new int;
*ptr = 5;
cout << *ptr << endl;

ptr = NULL;
// 3. IS THIS LINE A MEMORY LEAK OR DANGLING POINTER?


cout << *ptr << endl;
// 4. WHAT HAPPENS WITH THE ABOVE OUTPUT STATEMENT?



delete ptr;
cout << *ptr << endl;
// 5. WHAT HAPPENS WITH THE ABOVE OUTPUT STATEMENT? IS THIS MEMORY LEAK OR DANGLING POINTER?



double **dptr;

dptr = new double*[5];
for (int i=0; i<5; ++i)
    dptr[i] = new double[3];

// 6. HOW MANY ROWS IN dptr?


// 7. HOW MANY COLUMNS IN EACH ROW?


// Notice that we can treat this as a normal 2D array! No * Needed.
for (int i=0; i<5; ++i)
    for (int j=0; j<3; ++j)
        dptr[i][j] = 1.5;

// WRITE LINES OF CODE HERE TO DELETE ALL THE SPACE ALLOCATED FOR dptr 

    // Pause and exit the program
    system("Pause");
    return 0;
} 