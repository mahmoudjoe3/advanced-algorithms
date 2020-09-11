#include <iostream>
#include <vector>
using namespace std;

/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*
*/

vector<bool>vist;
int res = 0;
int root = 0;
void Explore(vector<vector<int> >& adj, int x) {

    vist[x] = true;
    
    for (int vertex : adj[x]) {
        
        if (vist[vertex] == false) {
            Explore(adj, vertex);
        }

    }
}

void DFS(vector<vector<int> >& adj, int x)
{
    for (int i = 0; i < adj.size(); i++)
    {
        if (vist[i] == false)
        {
            Explore(adj, i);
            res++;
        }
    }
}
int number_of_components(vector<vector<int> > &adj) {
  //write your code here
    DFS(adj, root);
  return res;
}

void main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vist.resize(n);
  int x, y;
  for (size_t i = 0; i < m; i++) {
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
    vist[x - 1] = false;
    vist[y - 1] = false;
  }
  root = x;
  std::cout << number_of_components(adj);
}
