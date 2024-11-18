#include <iostream>
#include <vector>
using namespace std;

class dfm;

class dft{
    public:
        int ft;
        int in;
        dft(int f,int i)
        {
            ft = f;
            in = i;
        }
    friend void add(dft,dfm);
};

class dfm {
    public:
        int m;
        int cm;
        dfm(int m, int cm)
        {
            this->m = m;
            this->cm = cm;
        }
    friend void add(dft,dfm);
};

void add(dft o1, dfm o2)
{
    int dis1 = o1.ft*12 + o1.in;
    int  dis2 = o2.m*100 + o2.cm;
    dis1 = dis1 * 2.54;
    cout<<"add "<<dis1+dis2<<endl;
    cout<<"sub "<<dis1-dis2<<endl;
    

}      

int main()
{
    dft o1(6,4);
    dfm  o2(5,6);
    add(o1,o2);

}