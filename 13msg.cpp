#include <iostream>
#include<vector>
using namespace std;
const int INF = 1000000; 

void MSG( vector<vector<int>>& edges, int n, int k){
    vector<int> fdist(n, INF);
    vector <int> d(n,-1);
    vector<vector<int>> E(n, vector<int>(n, 0));
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        E[u][v] = w; 
    }

    fdist[n-1]=0;
    for(int i=n-2;i>=0;i--){
    for (int j=i+1;j<n;j++){
        if (E[i][j]>0 && fdist[j] != INF){
            if (fdist[i] > E[i][j] + fdist[j]) {
                fdist[i] = E[i][j] + fdist[j];
                d[i] = j;
        }
     }
    }
}
    cout<<"shortest path: ";
    int node=0;
    if (fdist[0] == INF) {
        cout << "No path found\n";
        return;
    }


    while(node!=-1){
        cout<<node<<" ";
        node=d[node];
    }
    cout<< "\n min cost: "<<fdist[0]<<endl;
}

int main(){
    int n,k;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> k;
    // vector<vector<int>> E(n, vector<int>(n, 0));
    // for (auto &edge : edges) {
    //     int u = edge[0], v = edge[1], w = edge[2];
    //     E[u][v] = w; 
    // }
    vector<vector<int>>edges(k,vector<int>(3));
    cout << "Enter edges (u v w) format:\n";
    for (int i = 0; i < k; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    MSG(edges,n,k);
    return 0;
}