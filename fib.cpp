#include<iostream>
using namespace std;

int main(){
    int a, b, fib, n, nt;

    cout<<"Enter the number of terms: ";
    cin>>n;

    a = 0;
    b = 1;

    cout<<a<<" "<<b<<" ";
    
    for (int i = 0; i<n-2; i++){
        nt = a+b;
        a = b;
        b = nt;
        cout<<nt<<" ";
    }
}