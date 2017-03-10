#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll c, s, e, t, graph[105][105], dp[105][1005];
bool can[105];

ll solve(ll u, ll quant)
{
	if(quant == t)
	{
		if(can[u]) return 0LL;
		else return INT_MIN;
	}
	
	if(dp[u][quant] != -1)
		return dp[u][quant];
		
	ll ans = INT_MIN;
	
	for(ll i = 1; i <= c; i++)
	{
		if(i == u) continue;
		
		ans = max(ans, solve(i, quant+1) + graph[u][i]);
	}
		
	return dp[u][quant] = ans;
}

main()
{
	ll num;
	while(cin >> c >> s >> e >> t && (c+s+e+t))
	{
		memset(can, false, sizeof can);
		memset(dp, -1, sizeof dp);
		
		for(ll i = 1; i <= c; i++)
			for(ll j = 1; j <= c; j++)
				cin >> graph[i][j];
		
		for(ll i = 0; i < e; i++)
		{
			cin >> num;
			can[num] = true;
		}
		
		cout << solve(s, 0) << endl;
	}
}
