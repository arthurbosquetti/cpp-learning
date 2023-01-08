# include <iostream>
# include <string.h>

using namespace std;

/* CHAPTER 7: C++ Pointers */

# define NUMBER_OF_EXAMPLES 4

void swapAddress(int *i, int *j);
void swapNumber(int* i, int* j);

int main(int argc, char *argv[]) {

    if (argc==1) {
        cout << "ERROR: YOU MUST INPUT AN EXPERIMENT NUMBER OR A NEGATIVE NUMBER (TO RUN ALL EXPERIMENTS)." << endl;
        return -1;
    }

    int i = atoi(argv[1]);
    bool run_all = (i<0);

    if (i >= NUMBER_OF_EXAMPLES) {
        cout << "ERROR: INVALID EXPERIMENT NUMBER. NUMBER MUST BE 0 <= i <= " << (NUMBER_OF_EXAMPLES-1) << "." << endl;
        return -1;
    }

    // Pointer declaration and usage
    if (i==0 || run_all) {
        /* POINTERS:
    
        Pointer variables store the memory address of other variables.

        &var gives var's address in the memory. 

        Pointers are declared:
            type *pointerName;
            type* pointerName; (preferred syntax)
        */
        
        int* pointVar, var;
        var = 10;
        pointVar = &var;
        cout << "pointVar has the memory address of var: pointVar = " << pointVar << endl;
        cout << "var = " << var << endl;
        cout << "&var = " << &var << endl;
        cout << "pointVar points to: *pointVar = " << *pointVar << endl;    // The dereference operator
        cout << "\n";
    }
    // Pointers to structs
    if (i==1 || run_all) {
        cout << "Using pointers on structs:" << endl;
        cout << "When using pointers to access struct members, use the '->' operator. Example:" << endl;
        cout << "   pointerVariableToStruct->structMember" << endl;
        cout << "This is equivalent to using the dereference operator (*) on the pointer and the '.' operator. Example:" << endl;
        cout << "   (*pointerVariableToStruct).structMember" << endl;
        cout << "But the '->' operators is more preferable since '.' has higher precedence over '*' and avoids errors in the code." << endl;
        cout << "\n";
    }
    // Pointers and arrays
    if (i==2 || run_all) {
        /* 
        Pointers can be used to store array elements.
        Arrays can use pointer notation to store and display its elements

        int *ptr; int arr[5];
        ptr = arr;

        ptr + 1 is equivalent to &arr[1]; ...
        Pointers can be used similarly in multidimentional arrays. Example:
            maxtrix[2][2] == *(*(matrix + 2) + 2)
        */
       float arr[5]; 
        // Insert data using pointer notation
        cout << "Enter 5 numbers (float): ";
        for (int i = 0; i < 5; ++i) {
            // store input number in arr[i]
            cin >> *(arr + i) ; // Equivalent to arr[i]
        }
        // Values can be displayed using either array or pointer notation:
        cout << "Displaying data: " << endl;
        for (int i = 0; i < 5; ++i) {
            // display value of arr[i]
            cout << *(arr + i) << endl ;
        }
    }
    // Pass by pointer, pass by reference
    if (i==3 || run_all) {
        int a = 10;
        int b = 20;

        cout << "Swapping address of a and b..." << endl;
        swapAddress(&a, &b);
        cout << "a is " << a << " and b is " << b << endl;
        
        cout << "Swapping a and b..." << endl;
        swapNumber(&a, &b);
        cout << "a is " << a << " and b is " << b << endl;
        return 0;
    }
    string result = (run_all) ? "Ran all examples." : "Ran a single example.";
    cout << result << endl;
    cout << "\n";

}
// Swap address that i and j point to (does not affect a,b since i,j are copies)
void swapAddress(int *i, int *j) {
    int temp = *i;
    i = j;
    j = &temp;
    cout << "*i is " << *i << " and *j is " << *j << endl;
}
// Swap values at the addresses of i,j which are the same as a,b. Hence affects a,b.
void swapNumber(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp; 
    cout << "*i is " << *i << " and *j is " << *j << endl;
}