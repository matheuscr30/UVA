#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

main()
{
  vector<ll>vet;
  ll n, num, m;

  while(cin >> n)
  {
    vet.clear();
    for (ll i = 0; i < n; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    cin >> m;
    cin.ignore();

    sort(vet.begin(), vet.end());

    ll lo = 0, hi = n-1, bl, bh;

    while(lo <= hi)
    {
      if (vet[lo] + vet[hi] == m)
      {
        bl = lo;
        bh = hi;
        lo++;
        hi--;
      }
      else if( vet[lo] + vet[hi] < m)
      {
        lo++;
      }
      else
      {
        hi--;
      }
    }

    cout << "Peter should buy books whose prices are " << vet[bl] << " and " << vet[bh] << "." << endl;
    cout << endl;
  }
}
