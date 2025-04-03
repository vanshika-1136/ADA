#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
const int INF=10000000;
void MSG(vector<vector<int>>& edges,int n){
    vector<int> stage(n,0);
    vector<vector<int>>E(n,vector<int>(n,0));
    vector<int>fDist(n,INF);
    vector<int>d(n,-1);
    for(auto edge:edges){
        int u =edge[0],v=edge[1],w=edge[2];
        E[u][v]=w;
    }

    stage[n-1]=1;
    fDist[n-1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j =i+1;j<n;j++){
        if(E[i][j]>0 && fDist[j]!=INF){
            stage[i]=max(stage[i],stage[j]+1);
            if (fDist[i] > E[i][j] + fDist[j]) {
                fDist[i] = E[i][j] + fDist[j];
                d[i] = j;
            }
        }
        }
    }
    
    int numStages= *max_element(stage.begin(),stage.end());
    cout<<" number of stages: "<<numStages<<endl;
    cout<<" shortest path : ";
    int node=0;
    if(fDist[0]==INF){
        cout<<"no path found\n";
        return;
    }

    while(node!=-1){
        cout<< node<<" ";
        node=d[node];
    }
    cout << "\nMinimum cost: " << fDist[0] << endl;
}
int main(){
    int n=6;
    vector<vector<int>>edges={
       { 0, 1, 2},
       {0, 2 ,3},
       {1, 3 ,2},
       {1, 4 ,3},
       {2, 4 ,1},
       {3, 5 ,4},
       {4, 5 ,2},
       {2, 3 ,5}
    };
    MSG(edges,n);
    return 0;
}