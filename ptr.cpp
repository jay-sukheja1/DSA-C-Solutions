#include<iostream>
using namespace std;
int main(){
    int a;
    a=10;
    int* p=&a;
    int** p2=&p;
    int* ptr=NULL;
    cout<<ptr<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;
}
#include<iostream>
using namespace std;
void changea(int* p){ //int %b
    *p=20;            //b=20
}
int main(){
    int a;
    a=10;
    cout<<a<<endl;
    changea(&a);
    cout<<a<<endl;
}