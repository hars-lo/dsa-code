#include <iostream>
using namespace std;

int Count = 0; // Global variable to keep track of object count

class Test {
public:
    Test() { // Constructor
        Count++;
        cout << "Count is " << Count << endl;
    }

    ~Test() { // Destructor
        Count--;
        cout << "Count is " << Count << endl;
    }
};

int main() {
    Test t1, t2, t3, t4; // Creating four objects of Test class
    return 0;
}
