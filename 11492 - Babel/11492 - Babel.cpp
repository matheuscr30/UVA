#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> is;
typedef vector< pair<int, string> > vii;
map<string, int> string_to_int;
vector< vii > grafo(4005);
bool visitados[4005][4005];
int indice;

int dijkstra(int origem, int destino)
{
  memset(visitados, false, sizeof visitados);

  priority_queue< pair<int, is>, vector< pair<int, is> >, greater< pair<int, is> > >pq;
  //priority_queue< pair<ii, string>, vector< pair<ii, string> >, greater< pair<ii, string> > >pq;
  pq.push({0, {origem, "A"}});

  while(!pq.empty())
  {
    int v = pq.top().second.first;
    int peso = pq.top().first;
    string anterior = pq.top().second.second;
    pq.pop();

    visitados[v][string_to_int[anterior]] = true;

    if (v == destino)
      return peso;

    for (int i = 0; i < grafo[v].size(); i++)
    {
      int u = grafo[v][i].first;
      string str = grafo[v][i].second;

      if (!visitados[u][string_to_int[str]] && anterior[0] != str[0])
      {
        visitados[u][string_to_int[str]] = true;
        pq.push({peso+str.size(), {u, str}});
      }
    }
  }

  return -1;
}

void verifica(string str)
{
  if (string_to_int.find(str) == string_to_int.end())
  {
    string_to_int[str] = indice;
    indice++;
  }
}

main()
{
  int n;
  string o, d, i1, i2, p;

  while(cin >> n && n != 0)
  {
    string_to_int.clear();

    for (int i = 0; i <= 4000; i++)
      grafo[i].clear();

    cin.ignore();
    cin >> o >> d;

    indice = 0;

    for (int i = 0; i < n; i++)
    {
      cin.ignore();
      cin >> i1 >> i2 >> p;

      verifica(i1);
      verifica(i2);
      verifica(p);

      grafo[string_to_int[i1]].push_back({string_to_int[i2], p});
      grafo[string_to_int[i2]].push_back({string_to_int[i1], p});
    }

    int res = -1;

    if (string_to_int.find(o) == string_to_int.end() || string_to_int.find(d) == string_to_int.end() || o == d)
      cout << "impossivel" << endl;
    else
    {
      res = dijkstra(string_to_int[o], string_to_int[d]);
      if (res == -1)
        cout << "impossivel" << endl;
      else
        cout << res << endl;
    }
  }
}
