#include<iostream>
using namespace std;
int main(){
    int n1, n2, n3, largest;
    cout<<"Enter three numbers:";
    cin>>n1>>n2>>n3;
if (n1 >= n2) {
    if (n1 >= n3) {
        largest = n1;
    } else {
        largest = n3;
    }
} else {
    if (n2 >= n3) {
        largest = n2;
    } else {
        largest = n3;
    }
}
std::cout << "The largest number is: " << largest;
    return 0;
}