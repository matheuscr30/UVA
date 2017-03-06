#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
vector<vector<ll> >grafo(1005);
ll dp[1005];

ll solve(ll v)
{
	if(dp[v] != -1)
		return dp[v];
	
	if(grafo[v].size() == 0)
		return 1LL;
		
	ll ans = 0LL;
	
	for(ll i = 0; i < grafo[v].size(); i++)
	{
		ans += solve(grafo[v][i]);
	}
		
	return dp[v] = ans;
}

main()
{
	ll n, num;
	bool flag = false;
	 
	while(cin >> n)
	{
		if(flag) cout << endl;
		for(ll i = 0; i < n; i++)
		{
			grafo[i].clear();
			ll k;
			cin >> k;
			
			for(ll j = 0 ; j < k; j++)
			{
				cin >> num;
				grafo[i].push_back(num);
			}
		}
		
		memset(dp, -1, sizeof dp);
		cout << solve(0) << endl;
		flag = true;
	}
}
