#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX
class Edge{
    public:
    int src,des,wt;
    Edge(int s,int d,int w): src(s),des(d),wt(w){}
};
struct compareEdge{
    bool operator()(const Edge &e1,const Edge &e2){
    return e1.wt>e2.wt;
    }
    
};


class disjointSet{
    public:
    vector<int>p;
    disjointSet(int n){
    p.resize(n);
    for(int i=0;i<n;++i){
        p[i]=-1;
    }
}
int find ( int u){
    while(p[u]>0){
    u=p[u];
    }
    return u;
}
void unionSet(int j,int k){
  p[j]=k;
}};
int kruskal(int e,vector<vector<int>>& cost ,int n, vector<Edge>&t){
    priority_queue<Edge,vector<Edge>,compareEdge> minHeap;

    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (cost[i][j]!=INF){
                minHeap.push(Edge(i, j, cost[i][j]));
            }
        }
    }
    disjointSet ds(n);
    int minCost=0.0;
    int i=0;
    while( i<n-1 && !minHeap.empty()){
        Edge nextEdge =minHeap.top();
        minHeap.pop();
        int j=ds.find(nextEdge.src);
        int k=ds.find(nextEdge.des);
        if(j!=k){
            // i=i+1;
            minCost=minCost+ nextEdge.wt;
            t.push_back(nextEdge);
            ds.unionSet(j,k);
            i++;
        }
    }
    if(i!=n-1){
        cout<<"no spanning tree"<<endl;
        return -1;
    } else{
   return minCost; }
}
int main(){
    int n,e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>> cost(n,vector<int>(n,INF));
    vector<Edge> t;
    cout << "Enter edges (source destination weight):\n";
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        cost[s][d] = cost[d][s] = w;

    }
     int min = kruskal(e,cost,n,t);
     cout<<"min cost of mst: "<<min<<endl;
     cout<<"edges in mst :";
    for(auto edge:t)
    {
        cout<<edge.src<<"--"<<edge.des<<"=="<<edge.wt<<endl;
    }
    return 0;

}

