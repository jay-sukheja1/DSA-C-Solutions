#include<iostream>
using namespace std;
int main(){
    int n;
    int num=1;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int h=0;h<i;h++){
            cout<<"  ";
        }
        for(int j=0;j<n-i;j++){
            cout<<num<<" ";
        }
        num++;
        cout<<endl;
    }
    return 0;
}