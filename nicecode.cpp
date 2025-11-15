#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<"*";
        if(i!=0){
        for(int h=0;h<=2*i-1;h++){
            cout<<" ";
        }
        cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n-2;i++){
        for(int j=0;j<i+1;j++){
            cout<<" ";
        }
        cout<<"*";
        if(i!=n-1){
            for(int h=0;h<=2*(n-2-i)-1;h++){
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
