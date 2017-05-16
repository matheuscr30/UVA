#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll r, c, graph[105][105], degree[105], dp[105][105], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void reset()
{
	memset(graph, 0, sizeof graph);
	memset(degree, 0, sizeof degree);
	memset(dp, -1, sizeof dp);
} 

ll solve(ll x, ll y)
{	
	if(dp[x][y] != -1)
		return dp[x][y];
		
	ll ans = 0LL;
	
	for(ll i = 0; i < 4; i++)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		
		if(nx < 0 || nx >= r || ny < 0 || ny >= c || graph[x][y] <= graph[nx][ny])
			continue;
			
		ans = max(ans, solve(nx, ny) + 1);
	}
	
	return dp[x][y] = ans;
}

main()
{
	ll n, x, y;
	string name;
	cin >> n;
	
	while(n--)
	{
		reset();
		cin.ignore();
		cin >> name >> r >> c;
		
		for(ll i = 0 ; i < r; i++)
			for(ll j = 0 ; j < c; j++)
				cin >> graph[i][j];
		
		ll maior = 0;
		for(ll i = 0 ; i < r; i++)
		{
			for(ll j = 0 ; j < c; j++)
			{
				ll res = solve(i, j)+1;
				maior = max(maior, res);
			}
		}
		
		cout << name << ": " << maior << endl;
	}
}
