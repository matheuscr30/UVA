#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
vector< vector<ll> >grafo(105);
ll dp[105];
bool visited[105];

ll solve(ll u)
{
	//cout << u << " ";
	if(dp[u] != -1)
		return dp[u];
	
	ll ans = 1LL;
	
	for(ll i = 0; i < grafo[u].size(); i++)
	{
		if(dp[grafo[u][i]] == -1)
			ans += solve(grafo[u][i]);
	}
		
	return dp[u] = ans;
}

main()
{
	ll n, k, v;
	
	while(cin >> n && n)
	{
		for(ll i = 1; i <= n; i++)
		{
			grafo[i].clear();
			cin >> k;
			for(ll j = 0 ; j < k; j++)
			{
				cin >> v;
				grafo[i].push_back(v);
			}
		}
		
		ll maxi = 0LL, indice;
		
		for(ll i = 1; i <= n; i++){
			memset(dp, -1, sizeof dp);
			ll res = solve(i);
		//	cout << endl;
			//cout << res << endl;
			
			if(maxi < res)
			{
				maxi = res;
				indice = i;
			}
		}
		//cout << endl;
				
		cout << indice << endl;
	}
}
