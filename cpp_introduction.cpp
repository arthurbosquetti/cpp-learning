#include <iostream>
#include <string>

using namespace std;


/* CHAPTER 1: C++ Introduction */

# define NUMBER_OF_EXAMPLES 3

int main(int argc, char *argv[]) {

    if (argc==1) {
        cout << "ERROR: YOU MUST INPUT AN EXPERIMENT NUMBER OR '-1' TO RUN ALL EXPERIMENTS." << endl;
        return -1;
    }

    int i = atoi(argv[1]);
    
    if (i >= NUMBER_OF_EXAMPLES || i < -1) {
        cout << "ERROR: INVALID EXPERIMENT NUMBER. NUMBER MUST BE -1 <= i <= " << (NUMBER_OF_EXAMPLES-1) << "." << endl;
        return -1;
    }
    
    // String output
    if (i==0 || i==-1) {
        cout << "Hello World!" << endl;
        cout << "This is my first C++ program!" << endl;
        cout << "\n";
    }
    // Number and character output
    if (i==1 || i==-1) {
        int num1 = 70;
        float num2 = 128.256;
        char ch = 'A';
        cout << num1 << endl;
        cout << num2 << endl;
        cout << "character: " << ch << endl;
        cout << "\n";
    }
    // Taking (multiple) inputs and outputs
    if (i==2 || i==-1) {
        int age;
        string name;
        cout << "Now let's try taking multiple inputs." << endl;
        cout << "Please enter your name and your age: ";
        cin >> name >> age;
        cout << "You are (" << name << ", " << age << ")." << endl;
        cout << "\n";
    }
    
    string result;
    result = (i==-1) ? "Ran all examples." : "Ran a single example.";
    cout << result << endl;
    cout << "\n";

    return 0;
}
