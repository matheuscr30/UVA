#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

main()
{
  vector<ll>constantes;
  ll c, n, num, d, k;
  cin >> c;

  while(c--)
  {
    constantes.clear();

    cin >> n;
    for (ll i = 0; i < n+1; i++)
    {
      cin >> num;
      constantes.push_back(num);
    }

    cin >> d >> k;

    ll i = 0,acum=0, num = 0, ant = 1;
    while(acum < k)
    {
      i+=d;
      acum += i;
      num++;
    }

    ll res = 0;
    for (ll i = 0; i < constantes.size(); i++)
    {
      res += constantes[i] * pow(num, i);
    }

    cout << res << endl;
  }
}
