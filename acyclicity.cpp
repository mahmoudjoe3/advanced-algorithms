#include <iostream>
#include <vector>
using namespace std;
/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*
*/
vector<bool> _vist;
bool has_cycle;

void Explore(int i, vector<vector<int> >& adj,int r) {
    _vist[i] = true;
    for (int vertx : adj[i]) {
        if (!_vist[vertx])
            Explore(vertx, adj, r);
        else if(r==vertx)
            has_cycle = true;
    }

}

void DFS(vector<vector<int> >& adj) {
    for (int i = 0; i < adj.size(); i++)
    {
        if (!_vist[i])
            Explore(i,adj,i);
    }
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
    DFS(adj);
  if (has_cycle)
      return 1;

  return 0;
}

void main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  _vist.resize(n);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    _vist[x - 1] = false; _vist[y - 1] = false;
  }
  has_cycle = false;
  std::cout << acyclic(adj);
}

