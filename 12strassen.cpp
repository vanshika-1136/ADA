#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> add(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n=mat1.size();
    // int col1=mat1[0].size();
    // int row2=mat2.size();
    // int col2=mat2[0].size();
    vector<vector<int>>result(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    return result;
}
vector<vector<int>> sub(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n=mat1.size();
    // int col1=mat1[0].size();
    // int row2=mat2.size();
    // int col2=mat2[0].size();
    vector<vector<int>>result(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    return result;
}
void print(vector<vector<int>>result){
    int row1=result.size();
    int col2=result[0].size();
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<int>>mul(const vector<vector<int>>mat1,const vector<vector<int>>mat2){
    int n=mat1.size();
    if (n == 1) {
        return {{mat1[0][0] * mat2[0][0]}};
    }
    int mid=n/2;
    vector<vector<int>>A11(mid,vector<int>(mid)),
                       A12(mid,vector<int>(mid)),
                       A21(mid,vector<int>(mid)),
                       A22(mid,vector<int>(mid)),
                       B11(mid,vector<int>(mid)),
                       B12(mid,vector<int>(mid)),
                       B21(mid,vector<int>(mid)),
                       B22(mid,vector<int>(mid));

    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            A11[i][j]=mat1[i][j];
            A12[i][j]=mat1[i][j+mid];
            A21[i][j]=mat1[i+mid][j];
            A22[i][j]=mat1[i+mid][j+ mid];
            B11[i][j]=mat2[i][j];
            B12[i][j]=mat2[i][j+mid];
            B21[i][j]=mat2[i+mid][j];
            B22[i][j]=mat2[i+mid][j+ mid];

        }
    }                   
                       
    vector<vector<int>>M1=mul(add(A11,A22),add(B11,B22));
    vector<vector<int>>M2=mul(add(A21,A22),B11);
    vector<vector<int>>M3=mul(A11,sub(B12,B22));
    vector<vector<int>>M4=mul(A22,sub(B21,B11));
    vector<vector<int>>M5=mul(add(A11,A12),B22);
    vector<vector<int>>M6=mul(sub(A21,A11),add(B11,B12));
    vector<vector<int>>M7=mul(sub(A12,A22),add(B21,B22));

    vector<vector<int>>result(n,vector<int>(n));
     vector<vector<int>> C11=add(sub(add(M1,M4) ,M5) ,M7),
                         C12=add(M3,M5),
                         C21=add(M2,M4),
                         C22=  add(add(sub(M1,M2),M3  ),M6);     
    
    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            result[i][j]=C11[i][j];
            result[i+mid][j]=C21[i][j];
            result[i][j+mid]=C12[i][j];
            result[i+ mid][j+ mid]=C22[i][j];
                
        }
    }   
    return result;                  
}
int main(){
    vector<vector<int>>m1={
       {1,2}, // {2,1,3,4},{1,2}
       {3,4} // {1,3,5,7},
        // {2,1,3,4},
        // {1,3,5,1}
    };
    vector<vector<int>>m2={
       {1,2},
       {3,4}
    };
    vector<vector<int>>result =mul(m1,m2);
    print(result);

    return 0;
}