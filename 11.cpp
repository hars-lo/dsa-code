#include<iostream>
using namespace std;

class p {
    public:
        int a;
        p(int n)
        {
            a=n;
        }
        p operator ^  (p &b){
            return a +b.a;
        }

};

class person {
    

    public:
    int age;
    int a;
    int b;
        person(int age)
        {
            this->age=age;
            cout<<"c called\n";
        }
        person(int age,int a,int b)
        {
            this->age=age;
            this->a=a;
            this->b=b;
            cout<<"c1 called\n";
        }
        
        person (person &obj)
        {
            this->a = obj.a;
            this->age = obj.age;
            cout<<"copu c called\n";
        }

        void dis()
        {
            cout<<this->age<<" "<<a<<" "<<b<<endl;
        }
        ~person(){

        }
};

int main()
{
    person p1(19,10,20);
    p1.dis();
    person* p2=new person(p1);
    p2->dis();
    cout<<p2->age;
    cout<<"output done";

    
}
