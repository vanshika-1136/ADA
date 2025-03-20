 #include<iostream>
 using namespace std;
 #include <vector>

int fMax( vector<vector<int>> &mat, int n ,int m ,int col){
   int index=0;
   int max=-1;
   for(int i =0;i<n;i++){
    if(mat[i][col]>max){
        max=mat[i][col];
        index=i;
    }
   }
   return index;
}
 vector<int> fPeak(vector<vector<int>> &mat){
    int n=mat.size(); //row
    int m =mat[0].size();

    if(m ==0 || n==0){
       return {-1, -1};
    }
     
     int low=0;
     int high=n-1;
     while(low<=high){
        int mid=(low+high)/2;
        int rowOfMaxEle =fMax(mat,n ,m ,mid);
        int left =((mid-1)>=0)?mat[rowOfMaxEle][mid-1]:-1;
        int right =((mid+1)>=0)?mat[rowOfMaxEle][mid+1]:-1;

        if(mat[rowOfMaxEle][mid-1]<mat[rowOfMaxEle][mid] && mat[rowOfMaxEle][mid+1]< mat[rowOfMaxEle][mid]){
            return {rowOfMaxEle, mid};
        }
        else if(mat[rowOfMaxEle][mid-1]>mat[rowOfMaxEle][mid]  ){
            high =mid-1;
        }
        else{
            low =mid+1;
        }

        
     }
     return {-1,-1};
 }
 int main(){
    int n,m;
    cout<<"Enter no. of rows: "<<n;
    cout<<"Enter no. of columns: "<<m;
    vector<vector<int>> mat(n,vector<int>(m));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    vector<int> peak=fPeak(mat);
    if (peak[0] != -1) {
        
        cout << "Peak element value: " << mat[peak[0]][peak[1]] << endl;
    } else {
        cout << "No peak element found." << endl;
    }
    return 0;
 } 
