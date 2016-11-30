#include <bits/stdc++.h>

using namespace std;

typedef struct{
  string nome;
  int l, h;
}marca;

main()
{
  bool flag2 = false;
  marca mar;
  vector<marca>vet;
  int t, d, l, h, q;
  string m;
  cin >> t;

  while(t--)
  {
    vet.clear();
    if (flag2)
      cout << endl;

    cin >> d;
    for (int i = 0 ; i < d; i++)
    {
      cin.ignore();
      cin >> m >> l >> h;
      mar.nome = m;mar.l = l;mar.h = h;
      vet.push_back(mar);
    }

    cin >> q;
    int o, cont;
    while(q--)
    {
      cin >> o;

      cont = 0;
      string win;
      for (int i = 0; i < vet.size(); i++)
      {
        if (vet[i].l <= o && o <= vet[i].h)
          cont++, win = vet[i].nome;

        if (cont > 1)
          break;
      }

      if(cont != 1)
        cout << "UNDETERMINED" << endl;
      else
        cout << win << endl;
    }

    flag2 = true;
  }
}
