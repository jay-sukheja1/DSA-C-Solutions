#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int h=1;h<=i+1;h++){
            cout<<h;
            
        }
        for(int k=i;k>=1;k--){
                cout<<k;
            }
        cout<<endl;
    }
    return 0;
}
