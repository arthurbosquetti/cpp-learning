# include <iostream>
# include <string.h>

using namespace std;


/* CHAPTER 4: C++ Ararys and Strings */

# define NUMBER_OF_EXAMPLES 3

struct Dog
    {
        char name[20];
        char breed[20];
        int age;
    };

Dog createDog();
void displayData(Dog &d);

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

    // Structures
    if (i == 0 || run_all) {
        Dog dog = createDog();
        displayData(dog);
    }
}

Dog createDog()
{
    Dog newDog;
    
    cout << "Generating a new dog..." << endl;
    cout << "Enter name: ";
    cin.getline(newDog.name, 20);
    cout << "Enter breed: ";
    cin.getline(newDog.breed, 20);
    cout << "Enter age: ";
    cin >> newDog.age;

    return newDog;
}

void displayData(Dog &d) {
    cout << "\nDisplaying Information:" << endl;
    cout << "Name: " << d.name << endl;
    cout <<"Breed: " << d.breed << endl;
    cout << "Age: " << d.age;
}