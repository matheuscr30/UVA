#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

main()
{
  vector<ll>vet;
  ll t, n, num;
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

    ll cont = 1;
    if (vet.size() >= 2) cont = 2;

    ll ini = vet[0];
    for (ll i = 1 ; i < vet.size()-1; i++)
    {
      if (ini+vet[i] < vet[i+1]){
        cont++;
        ini += vet[i];
      }
    }
    cout << cont << endl;
  }
}
