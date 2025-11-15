#include<iostream>
using namespace std;
int main(){
    int c,a,b;
    cout<<"1:+\n2:-\n3:*\n4:/\n";
    cout<<"Enter your choice: ";
    cin>>c;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    switch(c){
        case 1: cout<<"Sum: "<<a+b; break;
        case 2: cout<<"Difference: "<<a-b; break;
        case 3: cout<<"Product: "<<a*b; break;
        case 4: 
            if(b!=0)
                cout<<"Quotient: "<<a/b; 
            else
                cout<<"Error: Division by zero"; 
            break;
        default: cout<<"Invalid choice";
        
    }
}