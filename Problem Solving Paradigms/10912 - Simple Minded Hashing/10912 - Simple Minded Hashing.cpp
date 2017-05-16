#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll l, s, dp[10005][30];

ll solve(ll length, ll last)
{
	if (length == 0)
	{
		if (sum == 0)
			return 1LL;
		else
			return 0LL;
	}
	
	if (dp[length][sum] != -1)
		return dp[length][sum];
		
	ll ans = 0LL;
	
	for(ll i = last; i <= 23; i++)
	{
		ans += solve(length-1, sum-i);
	}
	
	return dp[length][sum] = ans;
}

main()
{
	memset(dp, -1, sizeof dp);
	while(cin >> l >> s && (l+s))
	{
		cout << solve(l, 1) << endl;
	}
}
