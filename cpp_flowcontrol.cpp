# include <iostream>
# include "goto.h"

using namespace std;


/* CHAPTER 2: C++ Control Flow */

# define NUMBER_OF_EXAMPLES 3

int main(int argc, char *argv[]) {

    if (argc==1) {
        cout << "ERROR: YOU MUST INPUT AN EXPERIMENT NUMBER OR A NEGATIVE NUMBER (TO RUN ALL EXPERIMENTS)." << endl;
        return -1;
    }

    int i = atoi(argv[1]);
    bool run_all = (i<0);

    if (i >= NUMBER_OF_EXAMPLES) {
        cout << "ERROR: INVALID EXPERIMENT NUMBER. NUMBER MUST BE i <= " << (NUMBER_OF_EXAMPLES-1) << "." << endl;
        return -1;
    }
    
    // do..while Loop
    if (i == 0 || run_all) {
        bool condition = false;
        do {
            string result = (condition) ? "true" : "false";
            cout << "I did something. condition = " << result << endl;
            condition = !condition;
        }
        while (condition);
        cout << "\n";
    }
    // switch..case Statement
    if (i == 1 || run_all) {
        char oper;
        float num1, num2;
        cout << "Enter an operator (+, -, *, /): ";
        cin >> oper;
        cout << "Enter two numbers: " << endl;
        cin >> num1 >> num2;

        switch (oper) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case '/':
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                break;
            default:
                cout << "Error! The operator is invalid";
                break;
        }
        cout << "\n";
    }
    // goto Statement
    if (i== 2 || run_all) {
        /* The goto statement gives the power to jump to any part of a program but, makes the logic of the 
        program complex and tangled. In modern programming, the goto statement is considered a harmful construct 
        and a bad programming practice.
        */
        (void) gotoStatement();
        cout << "\n";
    }
    






    string result = (run_all) ? "Ran all examples." : "Ran a single example.";
    cout << result << endl;
    cout << "\n";

    return 0;
}
