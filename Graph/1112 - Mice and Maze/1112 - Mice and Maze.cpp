#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dist[105];
vector<vector<pair<int, int> > >grafo(105);
bool visitados[105];
int teste, n, e, t, m, u, v, w;

int dijkstra(int source)
{
  memset(visitados, false, sizeof visitados);
  priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  for (int i = 1; i <= n; i++)
    dist[i] = INF;

  int ans = 1;
  dist[source] = 0;
  visitados[source] = true;
  pq.push({dist[source], source});

  while(!pq.empty())
  {
	int datual = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (datual > t)
		break;

    for (int i = 0; i < grafo[u].size(); i++)
    {
      int v = grafo[u][i].first;
      int custo = grafo[u][i].second;

      if (!visitados[v] and (dist[u] + custo) <= t) {

          visitados[v] = true;
          dist[v] = dist[u] + custo;
          pq.push({dist[v], v});
          ++ans;
      }
	}
  }

  return ans;
}

main()
{
  bool flag = false;
  cin >> teste;

  while(teste--)
  {

    cin >> n >> e >> t >> m;

    for (int i = 0; i <= n; i++)
      grafo[i].clear();

    for (int i = 0; i < m; i++)
    {
      cin >> u >> v >> w;
      grafo[v].push_back({u, w});
    }

    if (flag)
		cout << endl;

    cout << dijkstra(e) << endl;

    flag = true;
  }
}
