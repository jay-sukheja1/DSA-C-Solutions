#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        char alpha='A';
        for(int j=1;j<=i;j++){
            if(i%2==0){
                cout<<alpha;
                alpha++;
            }
            else{
                cout<<j;
            }
        }
        cout<<endl;
    }
}