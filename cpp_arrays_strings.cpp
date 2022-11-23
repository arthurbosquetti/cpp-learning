# include <iostream>
using namespace std;


/* CHAPTER 4: C++ Ararys and Strings */

# define NUMBER_OF_EXAMPLES 3

void display(int n[][3][2]);
void display(string s);
void display(char c[]);

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
    
    // Arrays
    if (i == 0 || run_all) {
        int arr[] = {19, 11, 8, 17, 9, 15};
        cout << "Printing the array prints its memory address: arr = " << arr << endl;
        cout << "If I want to print the array elements, I can use a for loop:" << endl;
        // Using the a reference to the elements in 'arr' make it possible to change them. It is more memory efficient,
        // since I'm not copying the value of the element to 'n'. 'n' is just a reference.
        for (const int &n : arr) { cout << n << " "; }
        cout << "\n";
        int sum = 0;
        int length = sizeof(arr)/sizeof(arr[0]);
        // for (int j = 0; j < length; ++j) {
        for (const int &n : arr) { sum += n; }
        cout << "Sum = " << sum << endl;
        cout << "Avg = " << (double) sum/length << endl;

        cout << "\n";
    }
    // Multidimensional arrays
    if (i == 1 || run_all) {
        cout << "Passing multidimensional arrays as function parameters looks like this:" << endl;
        cout << "   returnType functionName(dataType arrayName[?Empty][arraySize][arraySize]) {" << endl;
        cout << "       // code;" << endl;
        cout << "    }\nWe can see that it is not necessary to specify the number of rows.\n" << endl;
        int num[2][3][2] = {
                            {{3,4},{9,5},{7,1}},
                            {{1,2},{3,2},{0,7}}
                           };
        display(num);
        cout << "\n";
    }
    // C-strings
    if (i == 2 || run_all) {
        char sentence[100];
        cout << "Please enter a sentence: ";
        cin.get(sentence, 100);
        cin.ignore();
        string greet;
        cout << "Enter your favorite greeting: ";
        getline(cin, greet);
        display(sentence);
        display(greet);
        cout << "\n";
    }

    string res;
    res = (i==-1) ? "Ran all examples." : "Ran a single example.";
    cout << res << endl;
    cout << "\n";

    return 0;
}

void display(int n[][3][2]) {
    cout << "Displaying values of a multidimensional array:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                cout << "num[" << i << "][" << j << "][" << k << "]: " << n[i][j][k] << endl;
            }
        }
    }
}   
 
void display(string s) {
    cout << "Displaying your string: " << s << endl;
}

void display(char c[]) {
    cout << "Displaying your C-String/array of characters: " << c << endl;
}