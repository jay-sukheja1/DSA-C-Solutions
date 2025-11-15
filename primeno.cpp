#include<iostream>
using namespace std;
bool isPrime(int n) {
    if (n<=1){ 
        return false;
    }
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) 
        return false;
    }
    return true;
}

int  primeinrange(int n) {
    if (n<=1){
        return -1;
    }
    for (int i=2;i<=n;i++){
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }        
    return 0;
}

int main(){
    int a;
    cout << "Enter a number: ";
    cin >> a;
    primeinrange(a);
}