#include <iostream>
#include <vector>

using namespace std;

void primMST(vector<vector<int>>& cost, int V) {
    vector<int> near(V, 0); 
    vector<vector<int>> mstEdges(V - 1, vector<int>(2));

    int u = 0, v = 0, minCost = -1;

    
    for (int i = 0; i < V; i++) {
        for(int j=0;j<V;j++) {
            if(cost[i][j]> 0 && (minCost==-1 || cost[i][j] < minCost))
            if (cost[i][j] > 0 && (minCost == -1 || cost[i][j] < minCost)) {
                minCost = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    // Step 2: Add first edge (u, v) to MST
    mstEdges[0][0] = u;
    mstEdges[0][1] = v;

    // Mark u and v as part of MST
    near[u] = near[v] = 0;

    // Step 3: Initialize near[] array for remaining vertices
    for (int i = 0; i < V; i++) {
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v] && cost[i][u] > 0)
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // Step 4: Choose (n-2) more edges
    for (int j = 1; j < V - 1; j++) {
        int minEdge = -1, k = -1;

        // Choose a vertex where near[k] != 0 with minimum cost
        for (int i = 0; i < V; i++) {
            if (near[i] != 0 && cost[i][near[i]] > 0) {
                if (minEdge == -1 || cost[i][near[i]] < minEdge) {
                    minEdge = cost[i][near[i]];
                    k = i;
                }
            }
        }

        if (k != -1) {
            // Add selected edge to MST
            mstEdges[j][0] = k;
            mstEdges[j][1] = near[k];

            // Mark k as included in MST
            near[k] = 0;

            // Update near[] array
            for (int i = 0; i < V; i++) {
                if (near[i] != 0 && cost[i][k] > 0 && cost[i][k] < cost[i][near[i]]) {
                    near[i] = k;
                }
            }
        }
    }

    // Print the MST edges
    cout << "Edges in MST:\n";
    for (int i = 0; i < V - 1; i++) {
        cout << mstEdges[i][0] << " - " << mstEdges[i][1] << "\n";
    }
}

int main() {
    int V = 5;
    vector<vector<int>> cost = { {0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0} };

    primMST(cost, V);

    return 0;
}



