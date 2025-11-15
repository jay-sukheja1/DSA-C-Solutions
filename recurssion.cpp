#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void printnums(int n){
    cout<<n<<" ";
    if(n==1){return;}
    printnums(n-1);
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}

int sumofnnums(int n){
    if(n==0){
        return 0;
    }
    return n+sumofnnums(n-1);
}

int fibonacci(int n){    // O(2^n)
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

bool issorted(vector<int> &arr,int n){
    if(n==1 || n==0){return true;}
   
    return arr[n-1]>=arr[n-2] && issorted(arr,n-1) ;
}

int bs(vector<int> &arr,int tar,int st,int end){
    int mid=st+(end-st)/2;
    if(st<=end){
        if(arr[mid]==tar){
            return mid;
        } else if (arr[mid]<tar){
            return bs(arr,tar,mid+1,end);
        } else {
            return bs(arr,tar,st,mid-1);
        }
    }
    return -1;
}

void printallsubsets(vector<int> &arr, vector<int> &ans, int i){
    if(i==arr.size()){
        for(auto val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }

    ans.push_back(arr[i]);      //include
    printallsubsets(arr,ans,i+1);
    ans.pop_back();            //exclude
    printallsubsets(arr,ans,i+1);
}


void getallsubsets(vector<int> &arr, vector<int> &ans, int i,vector<vector<int>> &powerset){
    if(i==arr.size()){
        powerset.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);      //include
    getallsubsets(arr,ans,i+1,powerset);
    ans.pop_back();            //exclude
    getallsubsets(arr,ans,i+1,powerset);
}
vector<vector<int>> subsets(vector<int> &arr){
    vector<vector<int>> powerset;
    vector<int> ans;

    getallsubsets(arr,ans,0,powerset);
    return powerset;
}


void getallsubsets2(vector<int> &arr, vector<int> &ans, int i,vector<vector<int>> &powerset){
    if(i==arr.size()){
        powerset.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);      //include
    getallsubsets(arr,ans,i+1,powerset);
    ans.pop_back();            //exclude
    getallsubsets(arr,ans,i+1,powerset);

    int idx=i+1;
    while(idx<arr.size() && arr[idx]==arr[idx-1]){
        idx++;
        return; 
    }
}
vector<vector<int>> subsets2(vector<int> &arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> powerset;
    vector<int> ans;

    getallsubsets(arr,ans,0,powerset);
    return powerset;
}


void permutations(vector<int> &arr,int idx,vector<vector<int>> &allperms){
    if(idx==arr.size()){
        allperms.push_back(arr);
        return;
    }

    for(int i=idx;i<arr.size();i++){
        swap(arr[idx],arr[i]);
        return permutations(arr,idx+1,allperms);
        swap(arr[idx],arr[i]);
    }
}
vector<vector<int>> permutation(vector<int> &arr){
    vector<vector<int>> allperms;
    permutations(arr,0,allperms);
    return allperms;
}


bool issafe(vector<string> &board,int col,int n,int row){
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row; i>=0; i--){
        int j=col-(row-i);
        if(j>=0 && j<n && board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void getnqueens(vector<string> &board,vector<vector<string>> &ans,int n,int row){
    if(row==n){
        ans.push_back({board});
        return;
    }

    for(int j=0;j<n;j++){
        if(issafe(board,j,n,row)){
            board[row][j]='Q';
            getnqueens(board,ans,n,row+1);
            board[row][j]='.';
        }
    }
}
vector<vector<string>> nqueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n,string(n,'.'));
    getnqueens(board,ans,n,0);
    return ans;
}

bool iscorrect(vector<vector<char>> &board,int row,int col,char dig){
    for(int i=0;i<board.size();i++){
        if(dig==board[row][i]){
            return false;
        }
    }
    for(int i=0;i<board[0].size();i++){
        if(dig==board[i][col]){
            return false;
        }
    }
    int sr=(row/3)*3;
    int sc=(col/3)*3;
    for(int i=sr;i<=sr+2;i++){
        for(int j=sc;j<=sc+2;j++){
            if(dig==board[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool sudokusol(vector<vector<char>> &board,int row,int col){
    int nextr=row;
    int nextc=col+1;
    if(row==9){
        return true;
    }
    if(board[row][col]!='.'){
        sudokusol(board,nextr,nextc);
    }
    if(nextc==9){
        nextr=row+1;
        nextc=0;
    }
    
    for(char dig='1';dig<='9';dig++){
        if(iscorrect(board,row,col,dig)){
            board[row][col]=dig;
            if(sudokusol(board,nextr,nextc)){
                return true;
            }
            board[row][col]='.';
        }
    }
    return false;
}
void sudoku(vector<vector<char>> &board){
    sudokusol(board,0,0);
}


void getans(vector<vector<int>> &mat,int r,int c,vector<string> &ans, string path){       // rat in a maze
    
    if(r<0 || c<0 || r>=mat.size() || c>=mat[0].size() || mat[r][c]==-1){
        return;
    }
    
    if(mat[r][c]==0){
        return;
    }

    if(r==mat.size()-1 && c==mat[0].size()-1){
        ans.push_back(path);
        return;
    }

    mat[r][c]=-1;    // visited
    
    getans(mat,r+1,c,ans,path+"D");     // down
    getans(mat,r-1,c,ans,path+"U");     // up
    getans(mat,r,c-1,ans,path+"L");     // left
    getans(mat,r,c+1,ans,path+"R");     // right

    mat[r][c]=1;  // unvisited
}
vector<string> maze(vector<vector<int>> &matrix){
    vector<string> ans;
    string path;
    getans(matrix,0,0,ans,path);
    return ans;
}


void getcombsum(vector<int> &arr,int i,vector<int> &combi,vector<vector<int>> &ans,int tar){
    set<vector<int>> s;
    if(tar==0){
        if(s.find(combi)==s.end()){       // to prevent duplicates
            ans.push_back(combi);
            s.insert(combi);
        }
        return;
    }
    if(tar<0){
        return;
    }
    if(i=arr.size()){
        return;
    }


    combi.push_back(arr[i]);
    getcombsum(arr,i+1,combi,ans,tar-arr[i]);
    getcombsum(arr,i,combi,ans,tar-arr[i]);
    combi.pop_back();
    getcombsum(arr,i+1,combi,ans,tar);
}
vector<vector<int>> combinationsum(vector<int> arr,int tar){
    vector<vector<int>> ans;
    vector<int> combi;
    getcombsum(arr,arr.size(),combi,ans,tar);
    return ans;
}


bool ispalindrome(string str){
    string revstr=str;
    reverse(revstr.begin(),revstr.end());
    if(str==revstr){
        return true;
    }
    return false;
}
void getallparts(string str,vector<string> &partitions,vector<vector<string>> &ans){
    int n=str.size();
    if(str.size()==0){
        ans.push_back(partitions);
        return;
    }

    for(int i=0;i<n;i++){
        string part=str.substr(0,i+1);
        if(ispalindrome(part)){
            partitions.push_back(part);
            getallparts(str.substr(i+1),partitions,ans);
            partitions.pop_back();
        }
    }
}
vector<vector<string>> partitionpalindrome(string str){
    vector<vector<string>> ans;
    vector<string> partitions;
    getallparts(str,partitions,ans);
    return ans;

}


void merge(vector<int> &arr,int st,int mid,int end){
    vector<int> temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        } else {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[i+st]=temp[i];
    }
}
void mergesorthelp(vector<int> &arr,int st,int end){
    if(st<end){
        int m=st+(end-st)/2;
        mergesorthelp(arr,st,m);
        mergesorthelp(arr,m+1,end);
        merge(arr,st,m,end);
    }
}

int partition(vector<int> &arr,int st,int end){    // arrange elements to left and right half according to pivot
    int idx=st-1;
    int pivot=arr[end];          // pivot is always last element of the array or the part of array
    for(int j=st;j<end;j++){
        if(pivot>=arr[j]){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}
void quicksort(vector<int> &arr,int st,int end){
    if(st<end){
        int pivotidx=partition(arr,st,end);
        quicksort(arr,st,pivotidx-1);  //left half
        quicksort(arr,pivotidx+1,end); // right half
    }
}

int mergeforcountinversion(vector<int> &arr,int st,int mid,int end){
    vector<int> temp;
    int i=st,j=mid+1;
    int invcount=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invcount+=mid-i+1;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[i+st]=temp[i];
    }
    return invcount;
}
int mergesorthelpforcountinversion(vector<int> &arr,int st,int end){
    if(st<end){
        int m=st+(end-st)/2;
        int lc=mergesorthelpforcountinversion(arr,st,m);
        int rc=mergesorthelpforcountinversion(arr,m+1,end);
        int invcount=mergeforcountinversion(arr,st,m,end);
        return lc+rc+invcount;
    }
    return 0;
}
int countinversions(vector<int> &arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}

// Knights Tour Problem
bool isvalid(vector<vector<int>> &grid,int row,int col,int expval,int n){
    if(grid[row][col]!=expval){
        return false;
    }
    if(row<0 || col<0 || row>=n || col>=n){
        return false;
    }
    if(expval==(n*n)-1){
        return true;
    }
    bool ans1=isvalid(grid,row+2,col+1,expval+1,n);
    bool ans2=isvalid(grid,row+1,col+2,expval+1,n);
    bool ans3=isvalid(grid,row-1,col+2,expval+1,n);
    bool ans4=isvalid(grid,row-2,col+1,expval+1,n);
    bool ans5=isvalid(grid,row-2,col-1,expval+1,n);
    bool ans6=isvalid(grid,row-1,col-2,expval+1,n);
    bool ans7=isvalid(grid,row+1,col-2,expval+1,n);
    bool ans8=isvalid(grid,row+2,col-1,expval+1,n);
    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}
bool checkvalidgrid(vector<vector<int>> &grid){
    return isvalid(grid,0,0,0,grid.size());
}

int main(){
    // printnums(4);
    // cout<<endl;
    // cout<<factorial(5)<<endl;
    // cout<<sumofnnums(5)<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<fibonacci(i)<<" ";
    // }
    // vector<int> arr={1,2,3};
    // vector<int> ans;
    // vector<vector<int>> ans1;
    // cout<<issorted(arr,5)<<endl;
    // cout<<bs(arr,4,0,4)<<endl;
    // subsets2(arr);
    // cout<<endl;
    // permutation(arr);
    vector<int> arr={1,3,5,10,2,6,8,9};
    cout<<mergesorthelpforcountinversion(arr,0,arr.size()-1)<<endl;
    return 0;
}