#include<iostream>
using namespace std;

class Hello {
public:
    //constructor
    Hello() {
        cout<<"I am constructor"<<endl;
    }
    int data=0;
    Hello(int val) {
        data=val;
        cout<<"Parameterized constructor is called"<<endl;
    }
    ~Hello() {
        cout<<"I am Destructor"<<endl;
    }
};

int main() {
    Hello h;

    Hello h1(67);
    cout<<h1.data<<endl;

    Hello &h2(h1);    // copy constructor
    cout<<h2.data<<endl;
    return 0;
}