#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<pair<int, int> > >grafo(1005);
int dist[1005];

bool BellmanFord(int vertice)
{
  for(int i = 0; i < n; i++)
    dist[i] = INT_MAX;

  dist[vertice] = 0;

  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < grafo[j].size(); k++){
        int u = j;
        int v = grafo[j][k].first;
        int peso = grafo[j][k].second;

        if (dist[u] != INT_MAX && dist[u] + peso < dist[v])
          dist[v] = dist[u] + peso;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < grafo[i].size(); j++)
    {
      int u = i;
      int v = grafo[i][j].first;
      int peso = grafo[i][j].second;

      if (dist[u] != INT_MAX && dist[u] + peso < dist[v])
        return true;
    }
  }

  return false;
}

void reset()
{
  for (int i = 0; i < n; i++)
    grafo[i].clear();
}

main()
{
  int c, u, v, w;
  cin >> c;

  while(c--)
  {
    cin >> n >> m;
    reset();

    for (int i = 0; i < m; i++)
    {
      cin >> u >> v >> w;
      grafo[u].push_back({v, w});
    }

    bool flag = BellmanFord(0);

    if (!flag) cout << "not ";
    cout << "possible" << endl;
  }
}
