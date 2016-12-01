#include <bits/stdc++.h>

using namespace std;

main()
{
  vector<pair<int, int> >ones, threes;
  int m;
  char num;

  while(cin >> m)
  {
    ones.clear();
    threes.clear();
    for(int i = 0; i < m; i++)
    {
      cin.ignore();
      for (int j = 0 ; j < m; j++)
      {
        cin >> num;
        if(num == '1')
          ones.push_back({i, j});
        else if (num == '3')
          threes.push_back({i, j});
      }
    }

    int dmenor = 0, p_menor, x1, y1, x2, y2;
    for (int i = 0; i < ones.size(); i++)
    {
      p_menor = INT_MAX;
      for (int j = 0; j < threes.size(); j++)
      {
        x1 = ones[i].first; y1 = ones[i].second;
        x2 = threes[j].first; y2 = threes[j].second;

        int cont = 0;
        int distancia = abs(x1-x2) + abs(y1-y2);

        p_menor = min(p_menor, distancia);
      }

      dmenor = max(dmenor, p_menor);
    }

    cout << dmenor << endl;
  }
}
