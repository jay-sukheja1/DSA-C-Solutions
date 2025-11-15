/*#include<iostream>
using namespace std;
int main(){
    int max=INT_MIN;
    const int size=5;
    int marks[size]={34,45,56,67,78};
    for(int i=0;i<=size;i++){
        if(marks[i]>max){
            max=marks[i];
        }
    }
   cout<<"The maximum marks is "<<max;
    return 0; 
} */
/* #include<iostream>
using namespace std;
void revarr(int arr[],int sz){
    int start=0,end=sz-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    };
}
void halfrevarr(int arr[],int sz){
    int start=0,end=sz/2-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    };
}
int main(){
    const int sz=5;
    int arr[sz]={1,2,3,4,5};
    revarr(arr,sz);
    return 0;
} */
/* #include<iostream>
using namespace std;
int sumarr(int arr[],int sz){
    int sum=0;
    for(int i = 0;i < sz;i++){
        sum+=arr[i];
    }
    return sum;
}
int prodarr(int arr[],int sz){
    int prod=1;
    for(int i = 0;i < sz;i++){
        prod*=arr[i];
    }
    return prod;
} */
/* #include<iostream>
using namespace std;
int swapmaxmin(int arr[],int sz){
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<sz;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Maximum is "<<max<<endl;
    cout<<"Minimum is "<<min<<endl;
    swap(max,min);
    cout<<"After swapping "<<endl;
    cout<<"Maximum is "<<max<<endl;
    cout<<"Minimum is "<<min<<endl;
    return 0;
} */
/* #include<iostream>
using namespace std;
int uniqueele(int arr[],int sz){
    for(int i=0;i<sz;i++){
        bool isUnique=true;
        for(int j=0;j<sz;j++){
            if(i!=j && arr[i]==arr[j]){
                isUnique=false;
                break;
            }
        }
        if(isUnique){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}
int main(){
    const int sz=7;
    int arr[sz]={1,2,3,2,4,5,1};
    uniqueele(arr,sz);
    return 0;
} */
/* #include<iostream>
using namespace std;
int intersection(int arr1[],int sz1,int arr2[],int sz2){
    for(int i=0;i<sz1;i++){
        for(int j=0;j<sz2;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
            }
        }
    }
    return 0;
} */

// subarrays
/* #include<iostream>
using namespace std;
int subarr(int arr[],int sz){    
    for(int st=0;st<sz;st++){
        for(int end=st;end<sz;end++){
            for(int k=st;k<=end;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}*/
/* #include<iostream>
using namespace std;
int maxsum(int arr[],int sz){
    int maxSum=INT_MIN;
    for(int st=0;st<sz;st++){
        int sum=0;
        for(int end=st;end<sz;end++){
            sum+=arr[end];
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
} */
/*#include<iostream>
using namespace std;
int kadane(int arr[],int sz){
    int currSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<sz;i++){
        currSum+=arr[i];
        maxSum=max(maxSum,currSum);
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}*/
/*#include<iostream>
using namespace std;
int pairsum(int arr[],int sz,int target){
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            if(arr[i]+arr[j]==target){
                cout<<arr[i]<<" "<<arr[j]<<endl;
                cout<<"Indices are "<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}*/
/*#include<iostream>
#include<vector>
using namespace std;
int majority(vector<int>nums){
    for(int val : nums){
        int count=0;
        for(int ele : nums){
            if(ele==val){
                count++;
            }
        }
        if(count>nums.size()/2){
            return val;
        }
        else{
            return -1;
        }
    }
}*/
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majorele(vector<int>& arr){
    sort(arr.begin(),arr.end());
    int count=1,n=sizeof(arr);
    int ele=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            count=1;
            ele=arr[i];
        }
    }
    return (count>n/2)?ele:-1;
}*/
/*#include<iostream>
#include<vector>
using namespace std;
int moore(vector<int>& arr){
    int count=0,ans=0;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            ans=arr[i];
        }
        if(arr[i]==ans){
            count++;
        }
        else{
            count--;
        }
    }
    int count1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==ans){
            count1++;
        }
    }
    return count1>arr.size()/2?ans:-1;
} */
#include<iostream>
using namespace std;
int exp(int base,int power){
    if(power==0){
        return 1;
    }
    if(base==0){
        return 0;
    }
    if(power<0 && base==0){
        cout<<"Undefined"<<endl;
        return -1;
    }
    if(base==-1 && power%2==0){
        return 1;
    }
    if(base==-1 && power%2!=0){
        return -1;
    }
    int result=1;
    long binaryPower=power;
    if(power<0){
        base=1/base;
        binaryPower=-1*power;
    }
    while(binaryPower>0){
        if(binaryPower%2==1){
        result*=base;
        }
    base*=base;
    binaryPower/=2;
    }
    return result;
}
#include<iostream>
#include<vector>
using namespace std;
int maxwater(vector<int>& height){
    int ans=0;
    int n=height.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ht=min(height[i],height[j]);
            int width=j-i;
            ans=max(ans,ht*width);
        }
    }
    return ans;
}
#include<iostream>
#include<vector>
using namespace std;
int maxwateropt(vector<int>& height){
    int left=0;
    int right=height.size()-1;
    int ans=0;
    while(left<right){
        int ht=min(height[left],height[right]);
        int width=right-left;
        ans=max(ans,ht*width);
        if(height[left]<height[right]){      // here opposite operations will make no sense 
            left++;                          // if left wall is smaller, dec right wall will make no change as water filling is dependent upon shorter one
        }
        else{
            right--;                         // same for this
        }
    }
    return ans;
}
#include<iostream>
#include<vector>
using namespace std;
vector<int> prodarrexself(vector<int>& nums){
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        int prod=1;
        for(int j=0;j<nums.size();j++){
            if(i!=j){
                prod*=nums[j];
            }
        }
        ans[i]=prod;
    }
    return ans;
}
#include<iostream>
#include<vector>
using namespace std;
vector<int> prodarrexselfopt(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=n-2;i>=0;i--){
        suffix*=nums[i+1];
        ans[i]*=suffix;
    }
    return ans;
}
int main(){
    
    return 0;
}