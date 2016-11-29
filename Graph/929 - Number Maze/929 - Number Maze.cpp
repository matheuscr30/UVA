#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
int matriz[1000][1000], n, m;
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0,1};
bool visitados[1000][1000];

bool valid(int x, int y)
{
  if (x >= 0 && x < n && y >= 0 && y < m)
    return true;
  return false;
}

int dijkstra(int origx, int origy, int destx, int desty)
{
  memset(visitados, false, sizeof visitados);

  priority_queue< pair<int, ii>, vector< pair<int, ii> >, greater <pair<int, ii> > >pq;
  pq.push({matriz[origx][origy], {origx, origy}});

  while(!pq.empty())
  {
    int peso = pq.top().first;
    int vx = pq.top().second.first;
    int vy = pq.top().second.second;
    pq.pop();

    visitados[vx][vy] = true;

    if (vx == destx && vy == desty)
      return peso;

    for (int i = 0; i < 4; i++)
    {
      int novox = vx + dx[i];
      int novoy = vy + dy[i];

      if(valid(novox, novoy) && !visitados[novox][novoy])
        visitados[novox][novoy] = true, pq.push({peso + matriz[novox][novoy], {novox, novoy}});
    }
  }
}

main()
{
  int t;
  cin >> t;

  while(t--)
  {
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> matriz[i][j];

    int origx = 0, origy = 0;
    int destx = n-1, desty = m-1;

    cout << dijkstra(origx, origy, destx, desty) << endl;
  }
}
