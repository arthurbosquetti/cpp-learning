# include <iostream>
# include <string.h>

using namespace std;


/* CHAPTER 6: C++ Objects & Class */

# define NUMBER_OF_EXAMPLES 2

class Cuboid {
    private:
        float height;
        float width;
        float length;

    public:
        Cuboid(float height, float width, float length) {
            this->height = height;
            this->width = width;
            this->length = length;
        }
        // Copy constructor: copy data from one (Cuboid) object to the current one.
        Cuboid(Cuboid &cuboid) {
            height = cuboid.height;
            width = cuboid.width;
            length = cuboid.length;
        }
        // Empty constructor
        Cuboid() {};

        void setMeasurements(float height, float width, float length) {
            this->height = height;
            this->width = width;
            this->length = length;
        }

        void displayMeasurements() {
            cout << "Height: " << height << endl;
            cout << "Width : " << width << endl;
            cout << "Length: " << length << endl;
        }

        float calculateVolume() {
            return height*width*length;
        }

        Cuboid operator + (const Cuboid &cuboid) {
            Cuboid temp;
            temp.height = height + cuboid.height;
            temp.width = width + cuboid.width;
            temp.length = length + cuboid.length;
            return temp;
        }
};

int main(int argc, char *argv[]) {
    // Validating arguments
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

    // Copy Constructor
    if (i == 0 || run_all) {
       Cuboid cuboid1(11, 12, 13);
       Cuboid cuboid2(cuboid1);

       cout << "Volume of cuboid1: " << cuboid1.calculateVolume() << endl;
       cout << "Volume of cuboid2: " << cuboid2.calculateVolume() << endl;
    }

    // Operator Overloading
    if (i == 1 || run_all) {
        Cuboid cuboid1(3,5,7);
        Cuboid cuboid2(4,6,8);

        Cuboid cuboid3;
        cuboid3 = cuboid1 + cuboid2;
        cuboid3.displayMeasurements();    
    }

    string result = (run_all) ? "Ran all examples." : "Ran a single example.";
    cout << "\n" << result << endl;
    cout << "\n";

}