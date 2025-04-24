#include<iostream>
using namespace std;
#include <vector>

// bool abs (int a,int b){
//     if((a+b)==-(a+b))
// }
void print(vector<int>x,int n){
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(x[j]==i)
            cout<<"Q";
            else{
                cout<<".";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}
bool place(vector<int>x,int k, int i){
   for(int j=0;j <k;j++){
      if(x[j]==i || abs(x[j]-i)==abs(j-k)){
       return false;
      }
   }
   return true;
}

void nQueen(vector<int>&x,int k, int n){
    for(int i=0;i<n;i++){
       if( place(x,k,i)){
        x[k]=i;
        if(k==n-1){
           print(x,n);
        }
        else{
        nQueen(x,k+1,n);
        }
      }
    }
}
int main() {
    int n = 4;
    std::vector<int> x(n);
    nQueen(x, 0, n);
    return 0;
}
