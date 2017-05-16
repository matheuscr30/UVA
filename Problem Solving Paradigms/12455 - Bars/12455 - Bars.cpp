#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n,p, dp[25][1005];
vector<ll>vet;

ll solve(ll current, ll sum)
{
  if (sum == n)
    return 1LL;

  if (current == p || sum > n)
    return 0LL;

  if (dp[current][sum] != -1)
    return dp[current][sum];

  ll ans = solve(current+1, sum);
  if (sum + vet[current] < 1001)
    ans = max(ans, solve(current+1, sum + vet[current]));

  return dp[current][sum] = ans;
}

main()
{
  ll t, num;
  cin >> t;

  while(t--)
  {
    memset(dp, -1, sizeof dp);
    vet.clear();
    cin >> n;
    cin >> p;

    for (ll i = 0; i < p; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    ll res = solve(0, 0);
    if (res == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}
