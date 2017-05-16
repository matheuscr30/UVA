#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, m, dp[30][35];
bool special[30];
vector< vector<ll> >graph(30);

ll solve(ll u, ll moves)
{
	if(moves > m)
		return 0LL;
	if(moves == m && special[u])
		return 1LL;
	
	if(dp[u][moves] != -1)
		return dp[u][moves];
		
	ll ans = 0LL;
	
	for(ll i = 0; i < graph[u].size(); i++)
	{
		ll v = graph[u][i];
		ans += solve(v, moves+1);
	}
		
	return dp[u][moves] = ans;
}

main()
{
	char c, u, v, s;
	while(cin >> n)
	{
		for(ll i = 0; i <= n; i++)
			graph[i].clear(), special[i] = false;
		
		for(ll i = 0 ; i < n; i++)
		{
			cin.ignore();
			cin >> c >> u >> v >> s;
			
			graph[(ll)c - 'A'].push_back((ll)u - 'A');
			graph[(ll)c - 'A'].push_back((ll)v - 'A');
			
			if(s == 'x')
				special[(ll)c - 'A'] = true;
				
		}
		cin >> m;
		
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << endl;
	}
}
