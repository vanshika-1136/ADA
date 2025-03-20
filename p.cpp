#include <iostream>
#include <vector>

using namespace std;
#include <climits>

void prims(vector<vector<int>>&E,int n){
    vector<vector<int>>t (n-1,vector<int>(2));
    vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
    vector<int> near(n,INT_max);
    int min_cost=0;
    
    for (int i=0;)
    
    int k=-1,l=-1,min=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){   //Using j = i + 1 ensures each edge is checked only once.
            if(E[i][j]<min && E[i][j]!=0){
                min=E[i][j];
                k=i;
                l=j;
            }
        }
    }
    t[0][0]=k;
    t[0][1]=l;
    min_cost=min+min_cost;
    for (int i=0;i<n;i++){
        if(cost[i][k]<cost[i][l]){
            near
        }
    }
}
