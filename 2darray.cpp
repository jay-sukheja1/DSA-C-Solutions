#include<iostream>
using namespace std;

bool linearsearch(int matrix[][3],int rows,int columns,int n){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(matrix[i][j]==n){
                pair<int,int> pair={i,j}; 
                cout<<"("<<pair.first<<","<<pair.second<<")";
                return true;
            } 
        }
    }
    pair<int,int> pair2={-1,-1};
    cout<<"("<<pair2.first<<","<<pair2.second<<")";
    return false;
}

int maxrowsum(int matrix[][3],int rows,int cols){
    int maxsum=0;
    for(int i=0;i<rows;i++){
        int rowsum=0;
        for(int j=0;j<cols;j++){
            rowsum+=matrix[i][j];
        }

        maxsum=max(maxsum,rowsum);
    }
    return maxsum;
}

int maxcolsum(int matrix[][3], int rows, int cols){
    int maxsum=0;
    for(int j=0; j<cols; j++){
        int colsum=0;
        for(int i=0;i<rows;i++){
            colsum+=matrix[i][j];
        }

        maxsum=max(maxsum,colsum);
    }
    return maxsum;
}

int diagonalsum(int matrix[][3],int rows,int cols, int n){
    int sum=0;
    for(int i=0; i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i==j){
                sum+=matrix[i][j];  
            } else if (j==n-i-1) {
                sum+=matrix[i][j];
            }
        }
    }
    return sum;
}

int diagonalsumop(int matrix[][3],int rows,int cols, int n){
    int sum=0;
    for(int i=0; i<rows;i++){
        sum+=matrix[i][i];
        if(i!=n-i-1){
            sum+=matrix[i][n-i-1];
        }
    }
    return sum;
}

int main(){
    int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int matrix1[4][3];
    int sqmat[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    int rows=4;
    int columns=3;
    // cout<<matrix[3][1]<<endl;
    // matrix[2][1]=0;
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<columns;j++){
    //         cin>>matrix1[i][j];
    //     }
    // }
    // cout<<endl;
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<columns;j++){
    //         cout<<matrix1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    // int target=9;
    // linearsearch(matrix,rows,columns,target);
    // cout<<maxcolsum(matrix,rows,columns);
    cout<<diagonalsumop(sqmat,3,3,3);
    return 0;
}
