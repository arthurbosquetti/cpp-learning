# include <iostream>
# include <string.h>

using namespace std;


/* CHAPTER 5: C++ Pointers */

# define NUMBER_OF_EXAMPLES 4

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
        cout << "Enter 5 numbers: ";
        for (int i = 0; i < 5; ++i) {
            // store input number in arr[i]
            cin >> *(arr + i) ; // Equivalent to arr[i]
        // Values can be displayed using either array or pointer notation:
        cout << "Displaying data: " << endl;
        for (int i = 0; i < 5; ++i) {
            // display value of arr[i]
            cout << *(arr + i) << endl ;
        }
    }
    /* 
    FUNCTION CALL BY REFERENCE:
    
    Can use reference of values instead of actual values in the function arguments.
    Either:
        Pass by reference without pointers. Example:
            void swap(int &n1, int &n2) {
                int temp;
                temp = n1; n1 = n2; n2 = temp;
            }
        No need to return since changes are at the address of n1 and n2.
    Or:
        Pass by reference with pointers (address of variable). Example:
            void swap(int* n1, int* n2) {
                int temp;
                temp = *n1; *n1 = *n2; *n2 = temp;
            }
        Again, no need to return since the changes occur at the address of n1 and n2.
    */

    string result = (run_all) ? "Ran all examples." : "Ran a single example.";
    cout << result << endl;
    cout << "\n";
}