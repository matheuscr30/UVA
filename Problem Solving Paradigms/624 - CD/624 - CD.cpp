#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n, p, dp[25][5000];
vector<ll>vet;

ll solve(ll current, ll sum)
{
  if (sum > n)
    return 0LL;

  if (current == p || sum == n)
    return dp[current][sum] = sum;

  if (dp[current][sum] != -1)
    return dp[current][sum];

  ll ans = max(solve(current+1, sum), solve(current+1, sum+vet[current]));

  return dp[current][sum] = ans;
}

void path (ll i, ll j, ll ans) {

    if (i == p or j == ans)
      return;

    //cout << i << ' ' << j << '\n';
    //cout << dp[i][j] << ' ' << dp[i + 1][j + vet[i]] << '\n';

    if (dp[i+1][j + vet[i]] == ans) {

      //cout << "pegou " << vet[i] << '\n';
      cout << vet[i] << ' ';
      path (i + 1, j + vet[i], ans);
    }

    else
      path (i + 1, j, ans);
}

main()
{
  ll num;

  while(cin >> n)
  {
    vet.clear();
    memset(dp, -1, sizeof dp);
    cin >> p;

    for (int i = 0; i < p; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    ll ans = solve (0, 0);

    path (0, 0, ans);
    cout << "sum:" << ans << endl;
  }
}
