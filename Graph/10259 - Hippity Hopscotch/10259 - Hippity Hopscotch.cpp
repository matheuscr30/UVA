#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, k, graph[105][105], dp[105][105];

ll solve(ll x, ll y)
{
	if(dp[x][y] != -1)
		return dp[x][y];
		
	ll ans = 0LL;	
	
	for(ll i = -k; i <= k; i++)
	{
		if(i == 0) continue;
		ll nx = x + i;
		ll ny = y + i;
		
		
		if(nx >= 0 && nx < n && graph[x][y] < graph[nx][y])
			ans = max(ans, solve(nx, y) + graph[nx][y]);
			
		if(ny >= 0 && ny < n && graph[x][y] < graph[x][ny])
			ans = max(ans, solve(x, ny) + graph[x][ny]);
	}
	
	return dp[x][y] = ans;
}

main()
{
	ll t;
	bool flag = false;
	cin >> t;
	
	while(t--)
	{	
		if(flag)cout << endl;
		cin >> n >> k;
	
		for(ll i = 0; i <= n; i++)
			for(ll j = 0; j <= n; j++)
			{
				dp[i][j] = -1;
				graph[i][j] = 0;
			}
		
		for(ll i = 0; i < n; i++)
			for(ll j = 0; j < n; j++)
				cin >> graph[i][j];
			
		cout << solve(0, 0) + graph[0][0] << endl;
		flag = true;
	}
}
