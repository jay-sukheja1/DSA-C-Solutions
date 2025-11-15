#include<iostream>
#include<vector>
#include <algorithm>
#include<set>
#include<map>
#include<unordered_set>
#include <unordered_map>
using namespace std;

bool searchinrow(vector<vector<int>> arr, int target,int row){
    int n=arr[0].size();
    int st=0;
    int end=n-1;
    while(st<=end){      // BS on row in which target is present
        int mid=st+(end-st)/2;
        if(target==arr[row][mid]){
            return true;
        } else if (target>mid){
            st=mid+1;
        } else {
            end=mid-1;
        }
    }
    return false;
}

bool searchin2darr(vector<vector<int>> arr,int target){
    int m=arr.size();
    int n=arr[0].size();
    int stR=0,endR=m-1;
    while(stR<=endR){      // BS on whole matrix to find the row in which target is present
        int midR=stR+(endR-stR)/2;
        if(arr[midR][0]<=target && target<=arr[midR][n-1]){
            return searchinrow(arr,target,midR);
        }
        else if(target>=arr[midR][n-1]){
            stR=midR+1;
        }
        else{
            endR=midR-1;
        }
    }
    return false;
}

bool searchin2darr2(vector<vector<int>> arr,int target){
    int n=arr[0].size();
    int m=arr.size();
    int row=0,col=n-1;
    int mid=arr[row][col];
    while(col>=0 && row<m){
        if(target==arr[row][col]){
            return true;
        } else if (target<arr[row][col]){
            col--;
        } else {
            row++;
        }
    }
    return false;
}

void spiralmatrix(vector<vector<int>> mat ){
    int n=mat.size();
    int m=mat[0].size();
    int sR=0,eR=m-1,sC=0,eC=n-1;
    while(sR<=eR && sC<=eC){
        for(int i=sC;i<=eC;i++){     //top
            cout<<mat[sR][i]<<" ";
        }
        for(int i=sR+1;i<=eR;i++){     //right
            cout<<mat[i][eC]<<" ";
        }
        for(int i=eC-1;i>=sC;i--){     //bottom
            if(sR==eR){
                break;
            }
            cout<<mat[eR][i]<<" ";
        }
        for(int i=eR-1;i>=sR+1;i--){     //left
            if(eC==sC){
                break;
            }
            cout<<mat[i][sC]<<" ";
        }
        sR++;
        eR--;
        sC++;
        eC--;
    }
}

void twosum(vector<int> arr,int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int first=arr[i];
        for(int j=i+1;j<n;j++){
            int second=arr[j];
            int sum=first+second;
            if(sum==target){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}

void twosumbetter(vector<int> &arr, int target){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int st=0,end=n-1;
    while(st<end){
        int sum=arr[st]+arr[end];
        if(sum==target){
            cout<<st<<" "<<end<<endl;
        } else if (sum>target){
            end--;
        } else {
            st++;
        }
    }
}
vector<int> twosumopt(vector<int> &arr,int target){
    int n=arr.size();
    vector<int> ans;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        int first=arr[i];
        int second=target-first;
        if(m.find(second)!=m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
        }
        m[first]=i;
    }
    return ans;
}

vector<int> findmissrepeatval(vector<vector<int>> &arr){
    int n=arr.size();
    vector<int> ans;
    unordered_set<int> s;
    int a,b;
    int expsum=0,actsum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            actsum+=arr[i][j];
            if(s.find(arr[i][j]) != s.end()){
                int a=arr[i][j];
                ans.push_back(a);
            }
            s.insert(arr[i][j]);
        }
    }
    expsum=(n*n)+(n*n+1)/2; 
    b=expsum+a-actsum;
    ans.push_back(b);
    return ans;
}

bool findduplicate(vector<int> &arr){
    int n=arr.size();
    unordered_set<int> s;
    int a;
    for(int i=0;i<n;i++){
        if(s.find(arr[i])!=s.end()){
            a=arr[i];
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int finddupopt(vector<int> &arr){    //slow fast pointer approach also linked list concept
    int slow=arr[0],fast=arr[0];
    do{
        slow=arr[slow];  //+1
        fast=arr[arr[fast]];  //+2
    } while(slow!=fast);

    slow=arr[0];
    while(slow!=fast){
        slow=arr[slow];   //+1
        fast=arr[fast];   //+1
    }
    return slow;
}

vector<vector<int>> threesum(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> ans;
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        int a=arr[i];
        for(int j=i+1;j<n;j++){
            int b=arr[j];
            for(int k=j+1;k<n;k++){
                int c=arr[k];
                if(a+b+c==0){
                    vector<int> triplets={a,b,c};
                    sort(triplets.begin(),triplets.end());
                    if(s.find(triplets)==s.end()){
                        s.insert(triplets);
                        ans.push_back(triplets);
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> threesumbetter(vector<int> &arr){
    int n=arr.size();
    set<vector<int>> uniquetrip;
    for(int i=0;i<n;i++){
        int target=-1*arr[i];
        set<int> s;
        for(int j=i+1;j<n;j++){
            int b=arr[j];
            int tf=target-b;
            if(s.find(tf)!=s.end()){
                vector<int> triplets={target,b,tf};
                sort(triplets.begin(),triplets.end());
                uniquetrip.insert(triplets);
            }
            s.insert(b);
        }
    }
    vector<vector<int>> ans(uniquetrip.begin(),uniquetrip.end());
    return ans;
}

vector<vector<int>> threesumopt(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int st=i+1;
        int end=n-1;
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        while(st<end){
            int sum=arr[i]+arr[st]+arr[end];
            if(sum<0){
                st++;
            } else if(sum>0){
                end--;
            } else {
                ans.push_back({arr[i],arr[st],arr[end]});
                st++;
                end--;
                while(st<end && arr[st]==arr[st-1]){st++;}
            }
        }
    }
    return ans;
}

vector<vector<int>> foursum(vector<int> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]){
                continue;
            }
            int st=j+1;
            int end=n-1;
            while(st<end){
                long long sum=(long long)arr[i]+arr[j]+arr[st]+arr[end];
                if(sum<0){
                    st++;
                } else if(sum>0){
                    end--;
                } else {
                    ans.push_back({arr[i],arr[j],arr[st],arr[end]});
                    st++;
                    end--;
                    while(st<end && arr[st]==arr[st-1]){st++;}
                }
            }
        }
    }
    return ans;
}

int subarrsum(vector<int> &arr,int k){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}

int prefixsum(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> ps;
    int count=0;
    ps[0]=arr[0];
    for(int i=1;i<n;i++){
        ps[i]=ps[i-1]+arr[i];
    }
    unordered_map<int,int> m;
    for(int j=0;j<n;j++){
        if(ps[j]==k){
            count++;
        }
        int val=ps[j]-k;
        if(m.find(val)!=m.end()){
            count+=m[val];
        }
        if(m.find(ps[j])==m.end()){
            m[ps[j]]=0;
        }
        m[ps[j]]++;
    }
    return count;
}

int main(){
    vector<vector<int>> vect={{1,2,3},{4,5,6},{7,8,9}};
    // for(int i=0; i<vect.size();i++){
    //     for(int j=0; j<vect[i].size();j++){
    //         cout<<vect[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> arr={-1,0,1,2,-1,4};
    threesum(arr);
    return 0;
}