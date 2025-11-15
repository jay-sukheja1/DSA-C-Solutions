#include<iostream>
using namespace std;
int sumdigit(int i){
    int sum=0;
    while(i>0){
        sum+=i%10;
        i/=10;
    }
    return sum;
}
int main(){
    cout<<sumdigit(143);
    return 0;
}