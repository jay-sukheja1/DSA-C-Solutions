#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// sieve of eratosthenes
int countprime(int n){
    int ans=0;
    vector<bool> arr(n+1,true);
    for(int i=2; i<n; i++){
        if(arr[i]){
            ans++;
            for(int j=i*2;j<n;j+=i){
                arr[j]=false;
            }
        }
    }
    return ans;
}

int diginnum(int n){
    int num=n;
    while(num!=0){
        int digit=num%10;
        cout<<digit<<" ";
        num=num/10;
    }
    cout<<endl;
    cout<<(int(log10(n)+1))<<endl;   // shortcut for finding count of digits
    return 0;
}

bool isarmstrong(int n){
    int num = n;
    int sumofcubes=0;
    while(num!=0){
        int dig=num%10;
        sumofcubes+=(dig*dig*dig);
        num=num/10;
    }
    return sumofcubes==n;
}

int gcd(int a, int b){
    int gcd=1;
    if(a==b){gcd=a;}
    if(a==0){gcd=b;}
    if(b==0){gcd=a;}
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }
    return gcd;
}

int gcdopt(int a,int b){
    int gcd=1;
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        if(b>a){
            b=b%a;
        }
    }
    if(a==0) return b;
    return a;
}

int gcdrec(int a, int b){    // assuming a>b
    if(b==0) return a;
    return gcdrec(b,a%b);
}

int lcm(int a, int b){
    int gcd=gcdopt(a,b);
    return (a * b)/gcd;
}

int reversenum(int n){
    int rev=0;
    int num=n;
    while(num!=0){
        int digit=num%10;
        if(rev>INT_MAX/10 || rev<INT_MIN/10){
            return 0;
        }
        rev=rev*10+digit;
        num=num/10;
    }
    return rev;
}

void palindromenum(int n){
    if(n<0) return;
    int rev=reversenum(n);
    if(n==rev){
        cout<<"Palindrome"<<endl;
    } else {
        cout<<"Not Palindrome"<<endl;
    }
}

int main(){
    // int n=153;
    // if(isarmstrong(n)){
    //     cout<<"yes"<<endl;
    // } else {
    //     cout<<"no"<<endl;
    // }
    int a=2552,b=352;
    palindromenum(a);
    palindromenum(b);
    return 0;
}