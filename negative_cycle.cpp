#include <iostream>
#include <vector>
using namespace std;

/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*
*/

vector<int> dist;
int root;
void BellmanFord(vector<vector<int> >& adj, vector<vector<int> >& cost,int s) {
    int n = adj.size();
    dist.resize(n);
    for (int i = 0; i < n; i++)
        dist[i] = INT32_MAX;

    dist[s] = 0;
    for (int u = 0; u < n - 1; u++) {

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (dist[v] > dist[u] + cost[u][i]) {
                dist[v] = dist[u] + cost[u][i];
            }
        }

    }
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
    BellmanFord(adj, cost,root);

    for (int u = 0; u < adj.size(); u++) {
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (dist[v] > dist[u] + cost[u][i]&&dist[u]!=INT32_MAX) {
                return 1;
            }
        }
    }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
    if (i == 0)root = x;
  }
  std::cout << negative_cycle(adj, cost);
}
