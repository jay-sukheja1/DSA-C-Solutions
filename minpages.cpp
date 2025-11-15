#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool isvalid(vector<int> &arr,int n, int m, int maxallowedpages){
    int students=1,pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxallowedpages){
            return false;
        }
        if(pages+arr[i]<=maxallowedpages){
            pages+=arr[i];
        } else{
            students++;
            pages=arr[i];
        }
    }
    return students>m ? false:true;
}
int findPages(vector<int> &arr, int n, int m) {
    if(m>n){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int st=0,end=sum,ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        } else {
            st=mid+1;
        }
    }
    return ans;
}
int painterpartition(vector<int> &arr, int n, int m) {
    return findPages(arr,n,m);
}
bool isvalidcow(vector<int> &arr, int n, int m, int mindistance){
    int cows=1;
    int lastpos=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-lastpos>=mindistance){
            cows++;
            lastpos=arr[i];
        }
        if(cows==m){
            return true;
        }
    }
    return false;
}
int aggcows(vector<int> &arr, int n, int m) {
    sort(arr.begin(), arr.end());
    if(m>n){
        return -1;
    }
    int st=1,end=arr[n-1]-arr[0],ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalidcow(arr,n,m,mid)){
            ans=mid;
            st=mid+1;
        } else {
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums={1,2,8,4,9};
    int n=nums.size(),m=3;
    cout<<aggcows(nums,n,m);
    return 0;
}