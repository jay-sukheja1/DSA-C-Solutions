#include<iostream>
#include<vector>
using namespace std;
// int bublesort(vector<int>& arr){
//     int n = arr.size();
//     for(int i=0;i<n-1;i++){
//         bool swapped = false;
//         for(int j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(arr[j],arr[j+1]);
//                 swapped = true;
//             }
//         }
//         if(swapped){
//             return 0;
//         }
//     }
//     return 0;
// }
// int selectionsort(vector<int>& arr){
//     int n=arr.size();
//     for(int i=0;i<n-1;i++){
//         int smallidx=i;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]<arr[smallidx]){
//                 smallidx=j;
//             }
//         }
//         swap(arr[i],arr[smallidx]); 
//     }
//     return 0;
// }
// void insertionsort(int arr[], int n){
//     for(int i=1;i<n;i++){
//         int curr = arr[i];
//         int prev = i - 1;
//         while(prev >= 0 && arr[prev] > curr){
//             arr[prev+1] = arr[prev];
//             prev--;
//         }
//         arr[prev+1] = curr;
//     }
// }
void printArray(vector<int>& arr){
    int n=arr.size();
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
}
// void sortcolors(vector<int>& arr){
//     int count0=0,count1=0,count2=0;
//     for(int i=0;i<arr.size();i++){
//         if(arr[i]==0){
//             count0++;
//         }
//         else if(arr[i]==1){
//             count1++;
//         }
//         else{
//             count2++;
//         }
//     }
//     for(int i=0;i<count0;i++){
//         arr[i]=0;
//     }
//     for(int i=count0;i<count0+count1;i++){
//         arr[i]=1;
//     }
//     for(int i=count0+count1;i<arr.size();i++){
//         arr[i]=2;
//     }
// }
// // Dutch National Flag Algorithm(dnf)
// void sortcolorsdnf(vector<int>& arr){
//     int low=0,mid=0,high=arr.size()-1;
//     while(mid<=high){
//         if(arr[mid]==0){
//             swap(arr[low],arr[mid]);
//             low++;
//             mid++;
//         }
//         else if(arr[mid]==1){
//             mid++;
//         }
//         else{
//             swap(arr[mid],arr[high]);
//             high--;
//         }
//     }
// }
void mergesortarr(vector<int>& arr1,vector<int>& arr2,int m, int n){
   // int m=arr1.size(),n=arr2.size();
    int idx=m+n-1,i=m-1,j=n-1;
    while(i>=0 && j>=0){
        if(arr1[i]>=arr2[j]){
            arr1[idx]=arr1[i];
            idx--;
            i--;
        }
        else{
            arr1[idx]=arr2[j];
            idx--;
            j--;
        }
    }
    while(j>=0){
        arr1[idx]=arr2[j];
        idx--;
        j--;
    }
}
void nextpermutation(vector<int>& arr){
    int piv=-1;      //select pivot
    int n=arr.size();
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            piv=i;
            break;
        }
        if(piv==-1){
            vector<int> reverse(arr.begin(),arr.end());
            return;
        }
    }
    for(int i=n-1;i>arr[piv];i--){    //swap with rightmost element
        if(arr[i]>arr[piv]){
            swap(arr[i],arr[piv]);
            break;
        }
    }
    int j=piv+1,k=n-1;    //rev all elements
    while(j<=k){
        swap(arr[j],arr[k]);
        j++;
        k--;
    }
}
int main(){
    vector<int> arr={1,2,3,0,0,0};
    vector<int> arr1={4,5,6};
    int m=3,n=3;
    mergesortarr(arr,arr1,m,n);
    printArray(arr);
    return 0;
}