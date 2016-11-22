#include <bits/stdc++.h>

using namespace std;
const int INF = 1e8 + 7;
vector<vector<pair<int, int> > >grafo(205);
vector<int>business;
int n, dist[205];

void reset()
{
  for(int i = 0; i <= n; i++)
    grafo[i].clear();

  business.clear();
  business.push_back(0);
}

void BellmanFord(int vertice)
{
  for(int i = 0; i <= n+1; i++)
    dist[i] = INF;

  dist[vertice] = 0;

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      for (int k = 0; k < grafo[j].size(); k++){
        int u = j;
        int v = grafo[j][k].first;
        int peso = grafo[j][k].second;

        if (dist[u] != INF && dist[v] > dist[u] + peso)
          dist[v] = dist[u] + peso;

      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < grafo[i].size(); j++)
    {
      int u = i;
      int v = grafo[i][j].first;
      int peso = grafo[i][j].second;

      if (dist[u] != INF && dist[v] > dist[u] + peso)
        dist[v] = -INF;
    }
  }
}

main()
{
  int num, r, q, u, v, w, casos = 1;
  while(cin >> n)
  {
    reset();
    for(int i = 0 ; i < n; i++)
    {
      cin >> num;
      business.push_back(num);
    }

    cin >> r;

    for(int i = 0; i < r; i++)
    {
      cin >> u >> v;
      w = pow((business[v] - business[u]) , 3);
      grafo[u].push_back({v, w});
    }

    cin >> q;
    BellmanFord(1);
    cout << "Set #" << casos++ << endl;
    while(q--)
    {
      cin >> num;

      if (dist[num] < 3 || dist[num] == INF)
        cout << "?" << endl;
      else
        cout << dist[num] << endl;
    }
  }
}
