#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
bool graph[105][105];
ll n, dp[105][105];
ll dx[] = {-1, -1}, dy[] = {1, -1};

ll solve(ll x, ll y)
{
	if(x == 0){
		//cout << x << " " << y << endl;
		return 1LL;
	}
	
	if(dp[x][y] != -1)
		return dp[x][y];
		
	ll ans = 0LL;
	
	for(ll i = 0; i < 2; i++)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		
		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		
		if(graph[nx][ny])
			ans += solve(nx, ny)%1000007;
		else{
			nx += dx[i];
			ny += dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n || !graph[nx][ny]) continue;
			ans += solve(nx, ny)%1000007;
		}
	}
		
	return dp[x][y] = ans%1000007;
}

main()
{
	ll t, xstart, ystart, cases=1;
	char c;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		memset(dp, -1, sizeof dp);
		memset(graph, true, sizeof graph);
		
		for(ll i = 0; i < n; i++)
		{
			cin.ignore();
			for(ll j = 0; j < n; j++)
			{
				cin >> c;
				
				if(c == 'B') graph[i][j] = false;
				if(c == 'W') xstart = i, ystart = j;
			}
		}
		
		ll res = solve(xstart, ystart);
		cout << "Case " << cases++ << ": " << res << endl;
	}
}
