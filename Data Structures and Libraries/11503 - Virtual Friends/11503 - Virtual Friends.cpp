#include <bits/stdc++.h>

using namespace std;

map<string, int>mapa;
vector<int>parent, r, son;

int findSet(int i){
  return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
}

bool isSameSet(int i, int j)
{
  return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
  if(!isSameSet(i, j))
  {
    int x = findSet(i);
    int y = findSet(j);

    if (r[x] > r[y]){
      son[findSet(x)] += son[findSet(y)];
      parent[y] = x;
    }
    else
    {
      son[findSet(y)] += son[findSet(x)];
      parent[x] = y;
      if (r[x] == r[y]) r[y]++;
    }
  }
}

void reset(int n)
{
  mapa.clear();
  son.clear();
  parent.clear();
  r.clear();

  parent.push_back(0);
  son.push_back(1);
  r.push_back(0);
  for (int i = 1; i <= n; i++)
    parent.push_back(i), r.push_back(0), son.push_back(1);
}

main()
{
  int t, f, indice;
  string s1, s2;
  cin >> t;

  while(t--)
  {
    indice = 1;
    cin >> f;
    reset(f);

    for (int i = 0; i < f; i++)
    {
      cin >> s1 >> s2;

      if (!mapa.count(s1)) mapa[s1] = indice++;
      if (!mapa.count(s2)) mapa[s2] = indice++;
      unionSet(mapa[s1], mapa[s2]);

      int l = findSet(mapa[s2]);
      cout << son[l] << endl;
    }
  }
}
