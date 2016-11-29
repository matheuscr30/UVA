#include <bits/stdc++.h>

using namespace std;

vector<int>vet;
bool visitados[10000];
int bfs(int source, int destination)
{
  memset(visitados, false, sizeof visitados);
  queue<pair<int, int> >fila;
  fila.push({source, 0});
  visitados[source] = true;

  while(!fila.empty())
  {
    int atual = fila.front().first;
    int cont = fila.front().second;
    fila.pop();

    if (atual == destination)
      return cont;

    for (int i = 0; i < vet.size(); i++)
    {
      int novo = atual + vet[i];
      novo = novo%10000;

      if (!visitados[novo])
        fila.push({novo, cont+1}), visitados[novo] = true;

    }
  }

  return -1;
}

int main()
{
  int l, u, r, num, casos = 1;

  while(cin >> l >> u >> r && (l+u+r))
  {
    vet.clear();

    for(int i = 0; i < r; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    int res = bfs(l, u);

    cout << "Case " << casos++ << ": ";

    if (res == -1) cout << "Permanently Locked" << endl;
    else cout << res << endl;
  }

  return 0;
}
