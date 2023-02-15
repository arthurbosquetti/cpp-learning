# include <iostream>
# include <string.h>

using namespace std;

/* CHAPTER 8: C++ Inheritance */

# define NUMBER_OF_EXAMPLES 4

// Classes for examples 0 and 1
class Person {
    protected:
        int age;
        string name;
    
    public:
        void setName(string name) {this->name = name;}
        void setAge(int age) {this->age = age;}
        void introduce() {
            cout << "Hi, my name is " << name << " and I am " << age << " y/o." << endl;
        }
        // virtual keyword is used for functions that will be redefined in derived classes
        virtual void print() {
            cout << "Person is printing..." << endl;
        }
};

class Student : public Person {
    /*
    Deriving in...
        public mode    : inheritance occurs just as it is;
        protected mode : public members become protected;
        private mode   : all members become private;
    - private members are always private!
    */
    private:
        string university;
        float gpa;
    public:
        void setGpa(float gpa) {this->gpa = gpa;}
        void setUniversity(string university) {this->university = university;}
        void introduceAcademicInfo() {
            cout << "I study at " << university << " and my GPA is " << gpa << "." << endl;
        }
        void introduce() {
            Person::introduce();
            introduceAcademicInfo();
        }
        void print() override {
            cout << "Student is printing..." << endl;
        }
};

// Classes and functions for example 2
class ClassB;
class ClassA {
    public:
        ClassA() : numA(12) {}
    private:
        int numA;
         // friend function declaration
         friend int add(ClassA, ClassB);
};

class ClassB {
    public:
        ClassB() : numB(1) {}    
    private:
        int numB;
        // friend function declaration
        friend int add(ClassA, ClassB);
};

int add(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB);
}

// Class for example 3
template <class T>
class Calculator {
    private:
        T num1, num2;
    public:
        Calculator(T num1, T num2) {
            this->num1 = num1;
            this->num2 = num2;
        }
        T add() {return num1 + num2;}
        T subtract() {return num1 + num2;}
        T multiply() {return num1 * num2;}
        T divide() {return num1 / num2;}

        void displayResults() {
            cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
            cout << "+: " << add() << endl;
            cout << "-: " << subtract() << endl;
            cout << "*: " << multiply() << endl;
            cout << "/: " << divide() << endl;
        }
};

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

    Student student;
    student.setName("Joseph");
    student.setAge(26);
    student.setGpa(3.7);
    student.setUniversity("DTU");

    // Inheritance and function overriding:
    if (i==0 || run_all) {
        cout << "Introducing myself as a Person:" << endl;
        student.Person::introduce();
        cout << "Introducing myself as a Student:" << endl;
        student.introduce();
        cout << "\n";   
    }

    // Calling override function using pointer, and virtual keyword: 
    if (i==1 || run_all) {
        Person* person = &student;
        person->introduce();
        cout << "When we use the 'virtual' keyword, we ensure that pointers of the base class that\n";
        cout << "point to an object of the derived class will call the new version of the function.\n";
        person->print();
    }

    // Friend function:
    if (i==2 || run_all) {
        cout << "When two classes declare a function f as a friend function, this function can access\n";
        cout << "private data of both classes" << endl;
        ClassA objectA;
        ClassB objectB;
        cout << "Sum: " << add(objectA, objectB) << endl;
        cout << "When a class B is declared a friend class in A, all members of A can be accessed\n";
        cout << "from inside B (but not vice versa)." << endl;
        cout <<"\n";
    }

    // Class Templates
    if (i==3 || run_all) {
        Calculator<int> intCalculator(2, 1);
        Calculator<float> floatCalculator(2.1, 1.2);
        
        cout << "Int results: " << endl;
        intCalculator.displayResults();

        cout << "Float results: " << endl;
        floatCalculator.displayResults();

        cout << "We can also have class templates with multiple or default parameters. Ex:\n";
        cout << "'template <class T, class U, class V = int', where type int is the default for V\n";
        cout << "but can be replaced when an object is created." << endl; 
        cout <<"\n";
}

    string result = (run_all) ? "Ran all examples." : "Ran a single example.";
    cout << result << endl;
    cout << "\n";
}

