#include <iostream>
#include <vector>
using namespace std;
void multiply(vector<vector<int>>& mat1,vector<vector<int>>& mat2,vector<vector<int>>& result){
    int row1=mat1.size();
    int col1=mat1[0].size();
    int row2=mat2.size();
    int col2=mat2[0].size();
    if(col1!=row2){
        cout<<"mat mul not psbl";
        return;
    }
    result.assign(row1,vector<int>(col2,0));
    
    for(int i=0;i<row1;i++){
        for(int k=0;k<col1;k++){
         for(int j=0;j<col2;j++){
            result[i][j]+=mat1[i][k]*mat2[k][j];
        }
        // cout<<endl;
    }

}
}
// 

int main(){
    int row1=2,col2=2;
    // vector<vector<int>>result;
    // result.assign(row1,vector<int>(col2,0));
    // for(int i=0;i<row1;i++){
    //     for(int j=0;j<col2;j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> mat1={
        {1,2,3},
        {4,5,6}
    };
    vector<vector<int>> mat2={
        {1,2},
        {4,5},
        {7,8}
    };

    vector<vector<int>>result;
    multiply(mat1,mat2,result);
    for(int i=0;i<row1;i++){
        for(int k=0;k<col2;k++){
           cout<< result[i][k]<<" ";
        }
        cout<<endl;
    }
    // print(result);


    return 0;
}
