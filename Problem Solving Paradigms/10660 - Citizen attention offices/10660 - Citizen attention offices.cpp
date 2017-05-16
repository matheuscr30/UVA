#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
int matriz[5][5] = {{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}, {15, 16, 17, 18, 19}, {20, 21, 22, 23,24}};

bool sort_vet(pair<int, ii>p1, pair<int, ii>p2)
{
  if (p1.first == p2.first){
    return matriz[p1.second.first][p1.second.second] < matriz[p2.second.first][p2.second.second];
  }

  return p1.first > p2.first;
}

main()
{
  vector<int>res;
  vector<pair<int, ii> >vet;
  bool visitados[5][5];
  int t, n, r, c, p;
  cin >> t;

  while(t--)
  {
    vet.clear();
    res.clear();
    memset(visitados, false, sizeof visitados);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> r >> c >> p;
      vet.push_back({p, {r, c}});
    }

    sort(vet.begin(), vet.end(), sort_vet);

    int cont = 1;

    for (int i = 0; i < vet.size() && cont <= 5; i++)
    {
      int x = vet[i].second.first;
      int y = vet[i].second.second;
      visitados[x][y] = true;
      cont++;
      res.push_back(matriz[x][y]);
    }


      for(int i = 0; i < 5 && cont < 6; i++)
      {
        for (int j = 0; j < 5 && cont < 6; j++)
        {
          if (!visitados[i][j])
            res.push_back(matriz[i][j]), cont++;
        }
      }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
      if (i != 0) cout << " ";
      cout << res[i];
    }
    cout << endl;
  }
}
