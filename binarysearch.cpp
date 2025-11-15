#include<iostream>
#include<vector>
using namespace std;

int bisearch(vector<int> arr, int target){
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end){
        int mid = start + (end-start ) / 2;
        int midterm = arr[mid];

        if(midterm > target){
            end = mid - 1;
        }
        else if(midterm < target){
            start = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int bsrec(vector<int> arr, int target, int start, int end){
    int mid = start + (end - start) / 2;
    int midterm = arr[mid];
    if(start<=end){   
        if(midterm > target){
        return bsrec(arr, target, start, mid - 1);
        }
        else if(midterm < target){
        return bsrec(arr, target, mid + 1, end);
        }
        else{
        return mid;
        }
    }
    return -1;
}
int bsforrotarr(vector<int> arr, int target){
    int st=0,end=arr.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[st]<=arr[mid]){
            if(arr[st]<=target<=arr[mid]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        else{
            if(arr[mid]<=target<=arr[end]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
}
#include <iostream>
#include <vector>
using namespace std;
int peakindexinmountainarray(vector<int> arr){
    int st=1,end=arr.size()-2;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid-1]>arr[mid]){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return -1;
}
#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1;
        if(n==1){return nums[0];}
        while(st<=end){
            int m=st+(end-st)/2;
            if(m==0 && nums[0]!=nums[1]){return nums[m];}
            if(m==nums.size() && nums[n-1]!=nums[n-2]){return nums[m];}
            if(nums[m-1]!=nums[m] && nums[m]!=nums[m+1]){
                return nums[m];
            }
            if(m%2==0){
                if(nums[m-1]==nums[m]){
                    end=m-1;
                } else{
                    st=m+1;
                }
            }
            else{
                if(nums[m-1]==nums[m]){
                    st=m+1;
                } else{
                    end=m-1;
                }
            }
        }
        return -1;
    }
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
    return -1;
}
int main(){
    vector<int> arr1={1,3,5,7,9,11,13,15,17,19};
    int target1=7;
    cout<<bisearch(arr1,target1)<<endl;
}