#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n, visitados[20];
vector<ll>v;

bool ehprimo(ll num)
{
  for (ll i = 2; i <= sqrt(num); i++)
    if (num%i == 0) return false;

  return true;
}

void backtracking(ll current, ll num, vector<ll>aux)
{
  if (current == n && ehprimo(1+aux[aux.size()-1]))
  {
    cout << "1";
    for (int i = 0; i < aux.size(); i++)
      cout << " " << aux[i];
    cout << endl;
  }
  else
  {
    for(ll i = 2; i <= n; i++)
    {
    //  cout << v[num] << " " << i << endl;
      if (!visitados[i] and ehprimo(v[num] + i))
      {
        //cout << "dentro" << v[num] << " " << i << endl;
        aux.push_back(i);
        visitados[i] = true;

        backtracking(current+1, i, aux);

        visitados[i] = false;
        aux.pop_back();
      }

    }
  }
}

main()
{
  bool flag = false;
  int cases=1;
  vector<ll>aux;
  while(cin >> n)
  {
    if (flag) cout << endl;

    aux.clear();
    v.clear();
    v.push_back(0);
    for (ll i = 1; i <= n; i++)
        v.push_back(i);

    memset(visitados, false, sizeof visitados);
    cout << "Case " << cases++ << ":\n";
    backtracking(1, 1, aux);
    flag = true;
  }
}
