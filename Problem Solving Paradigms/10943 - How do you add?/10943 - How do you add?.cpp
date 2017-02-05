#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, k, dp[105][105];

inline ll solve(ll sum, ll quant)
{
	if (quant > k)
		return 0LL;
	
	if (sum == 0 and quant == k)
		return 1LL;
	
	ll &re = dp[sum][quant];
	if (re != -1)
		return re;
		
	ll ans = 0LL;
	
	for(int i = 0; i <= n; i++)
	{
		if (sum-i >= 0)
		{
			ans += solve(sum-i, quant+1)%1000000;
		}
	}
		
	return re = ans;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	while(cin >> n >> k && (n+k))
	{
		memset(dp, -1, sizeof dp);
		cout << solve(n, 0)%1000000 << endl;
	}
}
