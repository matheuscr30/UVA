#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll m, dp[55][55];

ll solve(ll n, ll k)
{
    if ( n == 0 && k == 0 ) 
		return 1LL;
    if ( n == 0) 
		return 0LL;
	if ( k == 0)
		return 0LL;
    
    if (dp[n][k] != -1)
		return dp[n][k];
   
    ll ans = 0LL;
    for (ll i = 1; i <= m; i++)
    {
        if( n-i >= 0)
			ans += solve( n-i, k-1 );
    }
    return dp[n][k] = ans;
}

main()
{
	ll n, k;
	while(cin >> n >> k >> m)
	{
		memset(dp, -1, sizeof dp);
		cout << solve(n, k) << endl;
	}
}
