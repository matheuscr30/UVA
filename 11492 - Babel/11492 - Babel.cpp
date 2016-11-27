#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector< pair<int, string> > vii;
map<string, int> string_to_int;
vector< vii > grafo(4005);
bool visitados[4005];
int indice;

int dijkstra(int origem, int destino)
{
  memset(visitados, false, sizeof visitados);

  priority_queue< pair<ii, string>, vector< pair<ii, string> >, greater< pair<ii, string> > >pq;
  pq.push({{0, origem}, "l"});

  while(!pq.empty())
  {
    int v = pq.top().first.second;
    int peso = pq.top().first.first;
    string anterior = pq.top().second;
    pq.pop();


    visitados[v] = true;

    if (v == destino)
      return peso;

    for (int i = 0; i < grafo[v].size(); i++)
    {
      int u = grafo[v][i].first;
      string str = grafo[v][i].second;

      if (v == origem)
      {
        visitados[u] = true;
        pq.push({{peso+str.size(), u}, str});
      }
      else if (!visitados[u] && anterior[0] != str[0])
      {
        visitados[u] = true;
        pq.push({{peso+str.size(), u}, str});
      }
    }
  }

  return -1;
}

void verifica(string str)
{
  if (!string_to_int.count(str))
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

    verifica(o);
    verifica(d);

    for (int i = 0; i < n; i++)
    {
      cin.ignore();
      cin >> i1 >> i2 >> p;

      verifica(i1);
      verifica(i2);

      grafo[string_to_int[i1]].push_back({string_to_int[i2], p});
      grafo[string_to_int[i2]].push_back({string_to_int[i1], p});
    }

    int res = dijkstra(string_to_int[o], string_to_int[d]);

    if (res == -1)
      cout << "impossivel" << endl;
    else
      cout << res << endl;
  }
}
