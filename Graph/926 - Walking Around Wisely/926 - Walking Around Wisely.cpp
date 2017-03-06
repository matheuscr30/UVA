#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
bool graph[35][35][6];
ll dp[35][35], xend, yend, n;
ll dx[] = {1, 0}, dy[] = {0, 1};

ll solve(ll x, ll y)
{
	//cout << x << " " << y << endl;
	if(dp[x][y] != -1)
		return dp[x][y];
	
	if(x == xend && y == yend)
		return 1LL;
	
	ll ans = 0LL;
	
	for(ll i = 0 ; i < 2; i++)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		
		if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
		
		if(!graph[x][y][0] && i == 1) continue;
		if(!graph[x][y][1] && i == 0) continue;
		
		ans += solve(nx, ny);
	}
		
	return dp[x][y] = ans;
}

main()
{
	char carac;
	ll w, c, xstart, ystart, x,y;
	cin >> c;
	
	while(c--)
	{
		memset(graph, true, sizeof graph);
		memset(dp, -1, sizeof dp);
	
		cin >> n;
		
		cin >> xstart >> ystart;
		cin >> xend >> yend;
		
		cin >> w;
		
		for(ll i = 0; i < w; i++)
		{
			cin >> x >> y >> carac;
			
			if(carac == 'S')
				graph[x][y-1][0] = false;
			else if(carac == 'N')
				graph[x][y][0] = false;
			else if(carac == 'W')
				graph[x-1][y][1] = false;
			else
				graph[x][y][1] = false;
		}
		
		cout << solve(xstart, ystart) << endl;
	}
}
