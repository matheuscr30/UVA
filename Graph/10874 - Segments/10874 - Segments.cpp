#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, lefti[20005], righti[20005], dp[20005][20005];

ll solve(ll x, ll position)
{
	//cout << x << " " << y << endl;
	if(x == n+1)
		return 1LL;
		
	if(dp[x][position] != -1)	
		return dp[x][position];
		
	ll ans = INT_MAX;
	
	if( <= lefti[x])
		ans = min(ans, solve(x+1, righti[x]) + righti[x]-y+1);
	else if(y >= righti[x])
		ans = min(ans, solve(x+1, lefti[x]) + y-lefti[x]+1);
	else
	{
		if(abs(y-lefti[x]) < abs(y-righti[x]))
			ans = min(ans, solve(x+1, righti[x]) + y-lefti[x] + righti[x]-lefti[x]+1);
		else
			ans = min(ans, solve(x+1, lefti[x]) + righti[x]-y + righti[x] -lefti[x]+1);
	}
	//cout << "volta " << x << " " << y << " " << ans << endl;
		
	return dp[x][y] = ans;
}

main()
{
	ll a, b;
	while(cin >> n && n)
	{
		for(ll i = 1; i <= n; i++)
		{
			cin >> lefti[i] >> righti[i];
		}
		
		for(ll i = 0; i <= n; i++)
			for(ll j = 0 ; j <= n; j++)
				dp[i][j] = -1;
		
		ll res = solve(1, 3);
		cout << res << endl;
	}
}
