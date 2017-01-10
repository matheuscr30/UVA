#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<ll>vet;

main()
{
  ll n, q, num;
  cin >> n;

  for (ll i = 0 ; i < n; i++)
  {
    cin >> num;
    vet.push_back(num);
  }

  cin >> q;

  while(q--)
  {
    cin >> num;

    ll lo = 0, hi = n-1, maior=-1, menor=-1;

    while(lo <= hi)
    {
      if (vet[lo] < num)
      {
        menor = vet[lo];
        lo++;
      }
      else break;
    }

    lo = 0; hi = n-1;
    while(lo <= hi)
    {
      if (vet[hi] > num)
      {
        maior = vet[hi];
        hi--;
      }
      else break;
    }

    if (menor == -1) cout << "X";
    else cout << menor;
    cout << " ";

    if (maior == -1) cout << "X";
    else cout << maior;
    cout << endl;
  }
}
