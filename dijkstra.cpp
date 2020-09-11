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

typedef pair<int, int> iPair;
vector<int>dist,parnt;
void dijkstra(vector<vector<int> >& adj, vector<vector<int> >& cost, int s)
{
    ///////////////////init//////////////////
    int n = adj.size();
    //heap
    priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

    dist.resize(n);
    parnt.resize(n);

    for (int i = 0; i < n; i++) {
        dist[i] = INT32_MAX;
        parnt[i] = -1;
    }

    dist[s] = 0;
    pq.push(make_pair(dist[s], s));
    /////////////////////////////////////////
    while (!pq.empty())
    {
        //Extract minimum//
        int u = pq.top().second;
        pq.pop();

        for (int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];

            if (dist[v] > dist[u] + cost[u][i]) {
                dist[v] = dist[u] + cost[u][i];
                parnt[v] = u;
                //change praiorty
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
    dijkstra(adj,cost,s);

    if (dist[t] != INT32_MAX)
        return dist[t];
  return -1;
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
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
