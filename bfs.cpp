#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*
*/
vector<int> dist, parnt;
void BFS(vector<vector<int> >& adj, int s)
{
    int n = adj.size();
    queue<int> q;
    dist.resize(n);
    parnt.resize(n);
    for (int i = 0; i < n;i++) {
        dist[i] = -1;
        parnt[i] = -1;
    }
    dist[s] = 0;
    parnt[s] = -1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                //discover it
                dist[v] = dist[u] + 1;
                q.push(v);
                parnt[v] = u;
            }
        }
    }
}

vector<int> ReconstructPath(int s, int t) {
    vector<int> result;
    while (t != s) {
        result.push_back(t);
        t = parnt[t];
    }
    reverse(result.begin(), result.end());
    return result;
}


int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
    BFS(adj, s);
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
