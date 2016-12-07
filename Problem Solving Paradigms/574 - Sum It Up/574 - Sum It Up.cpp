#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll t, n;
vector<ll>v;
map<vector<ll>, bool>solution;

void backtracking(ll current, ll sum, vector<ll>aux)
{
  if (sum == t)
    {
      vector<ll>lulu = aux;
      sort(lulu.rbegin(), lulu.rend());

      if (!solution[lulu])
      {
        for (ll i = 0; i < lulu.size(); i++)
        {
          if (i != 0) cout << "+";
          cout << lulu[i];
        }
        cout << endl;
        solution[lulu] = true;
      }
    }
  else if (sum > t) return;
  else
  {
    for (ll i = current; i < n; i++)
    {
      aux.push_back(v[i]);
      backtracking(i+1, sum + v[i], aux);
      aux.pop_back();
    }
  }
}

main()
{
  ll num;
  vector<ll>aux;
  while(cin >> t >> n && n != 0)
  {
    aux.clear();
    solution.clear();
    v.clear();
    cout << "Sums of " << t << ":\n";
    for (ll i = 0; i < n; i++)
    {
      cin >> num;
      v.push_back(num);
    }

    backtracking(0, 0, aux);
    if (solution.size() == 0) cout << "NONE" << '\n';
  }
}
