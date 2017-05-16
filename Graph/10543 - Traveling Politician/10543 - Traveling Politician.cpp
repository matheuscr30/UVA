#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, m, k, dp[55][25];
vector< vector<ll> >grafo(55);

ll solve(ll u,ll quant)
{
	//cout << u << " " << << quant << endl;
	if(quant > 20)
		return INT_MAX;
	
	if(u == n-1 && quant >= k)
		return quant;
	
	if(dp[u][quant] != -1)
		return dp[u][quant];
		
	ll ans = INT_MAX;
	
	for(ll i = 0; i < grafo[u].size(); i++)
	{
		ll v = grafo[u][i];
		if(v == u ) continue;
		
		ans = min(ans, solve(v, quant+1));
	}
		
	return dp[u][quant] = ans;
}

main()
{
	ll u, v;
	while(cin >> n >> m >> k && (n+m+k))
	{
		for(ll i = 0; i <= n; i++)
			grafo[i].clear();
			
		for(ll i = 0; i < m; i++)
		{
			cin >> u >> v;
			grafo[u].push_back(v);
		}
		
		memset(dp, -1, sizeof dp);
		
		ll res = solve(0, 1);
		if(res == INT_MAX)
			cout << "LOSER" << endl;
		else
			cout << res << endl;
	}
}
