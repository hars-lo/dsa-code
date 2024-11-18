#include <iostream>
using namespace std;

class GFG;

class F {
private:
    int a;

public:
    // Constructor to initialize 'a'
    F() : a(5) {}  // Initialize 'a' with a value

    void display(const GFG t)
    {
        cout << "The value of Private Variable = "
             << t.private_variable << endl; // Added 'endl'
        cout << "The value of Protected Variable = "
             << t.protected_variable << endl; // Added 'endl'
    }

    // Declare GFG as a friend class
    friend class GFG;
};

class GFG {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    GFG()
    {
        private_variable = 10;
        protected_variable = 99;
    }

    // Access the private member 'a' of class F
    void disp(const F& t)
    {
        cout << "Accessing private member of F: " << t.a << endl; // Corrected 'disp' method
    }

    // Declare F as a friend class
    friend class F;
};

// Driver code
int main()
{
    GFG g;
    F fri;
    
    fri.display(g); // Display GFG's private and protected members
    g.disp(fri);    // Display F's private member

    return 0;
}
