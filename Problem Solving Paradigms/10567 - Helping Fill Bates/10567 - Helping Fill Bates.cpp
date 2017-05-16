#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<vector<ll> >vet(500);
vector<ll>::iterator it;

main()
{
  ll q;
  string s, str;

  cin >> s;

  for (ll i = 0 ; i < s.size(); i++)
  {
    ll num = s[i];
    vet[num].push_back(i);
  }

  cin >> q;
  cin.ignore();

  while(q--)
  {
    getline(cin, str);

    ll pos = 0, posi;
    bool flag = true;
    for (ll i = 0 ; i < str.size() && flag; i++)
    {
      ll num = str[i];

      it = lower_bound(vet[num].begin(), vet[num].end(), pos);

      if (it != vet[num].end())
      {
        pos = (*it);
        pos++;
      }
      else
        flag = false;

      if (i == 0)
        posi = pos;
    }

    if (!flag)
      cout << "Not matched" << endl;
    else
    {
      cout << "Matched " << posi-1 << " " << pos-1 << endl;
    }
  }

}
