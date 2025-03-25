#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> add(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n= mat1.size();
    vector<vector<int>>result(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            result[i][j]=mat1[i][j]+mat2[i][j];
        }

   }
   return result;
}
vector<vector<int>> mul(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n=mat1.size();
    if(n==1){
        return {{mat1[0][0]*mat2[0][0]}};
    }
    int mid=n/2;
    vector<vector<int>>M1(mid,vector<int>(mid));
    vector<vector<int>>M2(mid,vector<int>(mid));
    vector<vector<int>>M3(mid,vector<int>(mid));
    vector<vector<int>>M4(mid,vector<int>(mid));
    vector<vector<int>>N1(mid,vector<int>(mid));
    vector<vector<int>>N2(mid,vector<int>(mid));
    vector<vector<int>>N3(mid,vector<int>(mid));
    vector<vector<int>>N4(mid,vector<int>(mid));

    // vector<vector<int>>result;
    for(int i =0;i<mid;i++){
        for(int j=0;j<mid;j++){
            M1[i][j]=mat1[i][j];
            M2[i][j]=mat1[i][j+mid];
            M3[i][j]=mat1[i+mid][j];
            M4[i][j]=mat1[i+mid][j+mid];
            N1[i][j]=mat2[i][j];
            N2[i][j]=mat2[i][j+mid];
            N3[i][j]=mat2[i+mid][j];
            N4[i][j]=mat2[i+mid][j+mid];
        }
    }

    vector<vector<int>> a00(mid,vector<int>(mid)),a01(mid,vector<int>(mid)),a10(mid,vector<int>(mid)),a11(mid,vector<int>(mid));
    vector<vector<int>>result(n,vector<int>(n));

    a00=add((mul(M1,N1)),(mul(M2,N3)));
    a01=add((mul(M1,N2)),(mul(M2,N4)));
    a10=add((mul(M3,N1)),(mul(M4,N3)));
    a11=add((mul(M3,N2)),(mul(M4,N4)));

    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
        result[i][j]=a00[i][j];
        result[i][j+mid]=a10[i][j];
        result[i+mid][j]=a01[i][j];
        result[i+mid][j+mid]=a11[i][j];
        }
    }


  return result;  

}
void print(vector<vector<int>> &result,int &row1,int &col2){
    // int row1, col2;
    for(int i=0;i<row1;i++){
       for(int j=0;j<col2;j++){
        cout<<result[i][j]<<" ";
       }
       cout<<endl;
    }
}
int main(){
    vector<vector<int>>mat1={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {1,2,3,4}
    };
    vector<vector<int>>mat2={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {1,2,3,4}
    };
    int row1 = mat1.size(), 
        col1 = mat1[0].size(), 
        row2 = mat2.size(), 
        col2 = mat2[0].size();
        vector<vector<int>>result=mul(mat1,mat2);
        print(result,row1,col2);
    return 0;
}