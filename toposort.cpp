#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*
*/

vector<bool>vist;

void Explore(vector<vector<int> >& adj, int i, vector<bool>& used, vector<int>& order) {
    //pre order
    vist[i] = true;

    for (int vertx : adj[i]) {
        if (!vist[vertx])
            Explore(adj, vertx,used,order);
    }
    //post order
    if (!used[i])
    {
        used[i] = true;
        order.push_back(i);
    }
}


void dfs(vector<vector<int> > &adj, vector<bool> &used, vector<int> &order) {
  //write your code here
    for (int i = 0; i < adj.size(); i++) {
        if (!vist[i] && !used[i]) {
            Explore(adj, i,used,order);
        }
    }
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<bool> used(adj.size(), 0);
  vector<int> order;
  //write your code here
  dfs(adj, used, order);
  reverse(order.begin(), order.end());
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vist.resize(n);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    vist[x - 1] = false; vist[y - 1] = false;
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
