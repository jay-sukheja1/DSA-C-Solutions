#include<iostream>
using namespace std;
class Vehicle{
public:
    string brand;
    void horn(){
        cout<<"beep...beep...";
    }
};
class Car:public Vehicle{
public:
    string model;
};
int main(){
    Car mycar;
    mycar.horn();
    mycar.brand="BMW";
    mycar.model="M";
    cout<<mycar.brand<<" "<<mycar.model;
return 0;
}