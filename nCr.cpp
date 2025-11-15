#include<iostream>
using namespace std;
int facto(int n){
    if(n<=1) 
        return 1;
    return n*facto(n-1);
}
int nCr(int n,int r){
    return facto(n)/(facto(r)*facto(n-r));
}
int main(){
    int n,r;
    cout<<"Enter n and r: ";
    cin>>n>>r;
    cout<<n<<"C"<<r<<" = "<<nCr(n,r);
    return 0;
}