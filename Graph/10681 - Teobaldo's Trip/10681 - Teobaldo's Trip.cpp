#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll c, e, d, dp[105][205];
vector< vector<ll> >grafo(105);

ll solve(ll u, ll quant)
{
	if(quant > d)
		return 0LL;
	
	if(u == e && quant == d)
		return 1LL;
		
	if(dp[u][quant] != -1)	
		return dp[u][quant];
		
	ll ans = 0LL;
	
	for(ll i = 0; i < grafo[u].size(); i++)
	{
		ll v = grafo[u][i];
		if(v == u) continue;
		
		ans += solve(v, quant+1) % INT_MAX;
	}
		
	return dp[u][quant] = ans % INT_MAX;
}

main()
{
	ll l, a, b, s;
	
	while(cin >> c >> l && (c+l))
	{
		for(ll i = 0; i <= c; i++)
			grafo[i].clear();
			
		for(ll i = 0; i < l; i++)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		
		cin >> s >> e >> d;
		
		memset(dp, -1, sizeof dp);
		ll res = solve(s, 0);
		//cout << res << endl;
		
		if(res)
			cout << "Yes, Teobaldo can travel." << endl;
		else
			cout << "No, Teobaldo can not travel." << endl;
	}
}
