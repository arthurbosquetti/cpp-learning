# include <iostream>
# include <string.h>

using namespace std;

/* CHAPTER 8: C++ Inheritance */

# define NUMBER_OF_EXAMPLES 4

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
    // ...


    string result = (run_all) ? "Ran all examples." : "Ran a single example.";
    cout << result << endl;
    cout << "\n";

}
