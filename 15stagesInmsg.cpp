#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
const int INF=1e6;
int MSG(vector<vector<int>> & edges ,int n){
     vector<int>fDist(n,INF);
     vector<int>d(n,-1);
     vector<int>stages(n,0);
     vector<vector<int>> E(n,vector<int>(n,0));

     for(auto &edge: edges){
        int u=edge[0],v=edge[1],w=edge[2];
      //   if(u>0 && u<n && v>0 && v<n){
           E[u][v]=w;
      //   }
     }
     stages[n-1]=0;

     for(int i =n-2;i>=0;i--){
        for(int j =i+1;j<n;j++){
            // if(E[i][j]>0 && fDist[j] !=INF){
               if(E[i][j]>0){
                stages[i]=max(stages[i],stages[j]+1);
               }
            }
        }
        int numStages= *max_element(stages.begin(),stages.end());
        cout << "Number of stages: " << numStages << endl;
     }
// }
int main(){
   int n, k;
   cout << "Enter number of vertices: ";
   cin >> n;

   cout << "Enter number of edges: ";
   cin >> k;

   vector<vector<int>> edges(k, vector<int>(3));
   cout << "Enter edges (u v w) format:\n";
   for (int i = 0; i < k; i++) {
       cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
   }

   MSG(edges, n);
   return 0;
}