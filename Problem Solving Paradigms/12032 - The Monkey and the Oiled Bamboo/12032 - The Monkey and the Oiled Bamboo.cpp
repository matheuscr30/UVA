#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll lo, hi;
vector<ll>vet;

bool can(ll value)
{
  ll in = 0;
  for(ll i = 0; i < vet.size(); i++)
  {
    if (value == 0 || vet[i]-in > value)
      return false;
    else if (vet[i]-in == value){
      value--;
    }

    in = vet[i];
  }

  return true;
}

ll solve()
{
  ll mid;
  while(lo <= hi)
  {
   //cout << lo << " " << mid << " " << hi << endl;
    mid = (lo+hi)/2;

    if(can(mid)){
      hi = mid-1;
    }
    else{
      lo = mid+1;
    }
  }

  return hi+1;
}

main()
{
  ll t, n, num, cases=1;
  cin >> t;

  while(t--)
  {
    vet.clear();
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    cout << "Case " << cases++ << ": ";
    if (vet.size() >= 2)
    {
      lo = vet[0];
      hi = vet[n-1];
      //cout << lo << " " << hi << endl;
      ll res = solve();
      cout << res << endl;
    }
    else
      cout << vet[0] << endl;

  }
}
