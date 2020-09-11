#include <iostream>
#include <vector>
using namespace std;
/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*
*/
vector<bool>visited;

int Conected_Graph_DFS(vector<vector<int> >& adj, int x) {
    //vist x
    visited[x] = true;
    //for each n in adj[x]
    for( int vertex : adj[x]) {
        //if not visted
        if (visited[vertex] == false) {
            //explor()
            Conected_Graph_DFS(adj, vertex);
        }
    }
    //return 0
    return 0;
}

int reach(vector<vector<int> >& adj, int x, int y) {
    //write your code here
    Conected_Graph_DFS(adj, x);

    return (visited[x]&&visited[y]);
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector< vector<int> > adj(n, vector<int>());
    visited.resize(n);
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
        visited[x - 1] = false;
        visited[y - 1] = false;
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
    return 0;
}
