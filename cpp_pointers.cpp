# include <iostream>
# include <string.h>

using namespace std;


/* CHAPTER 5: C++ Pointers */

# define NUMBER_OF_EXAMPLES 3



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

    if (i==1 || run_all) {
        cout << "Using pointers on structs:" << endl;
        cout << "When using pointers to access struct members, use the '->' operator. Example:" << endl;
        cout << "   pointerVariableToStruct->structMember" << endl;
        cout << "This is equivalent to using the dereference operator (*) on the pointer and the '.' operator. Example:" << endl;
        cout << "   (*pointerVariableToStruct).structMember" << endl;
        cout << "But the '->' operators is more preferable since '.' has higher precedence over '*' and avoids errors in the code." << endl;
        cout << "\n";
}

    string result = (run_all) ? "Ran all examples." : "Ran a single example.";
    cout << result << endl;
    cout << "\n";

}