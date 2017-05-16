#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, m, dp[105][105];
ll dx[] = {1, 0}, dy[] = {0, 1};
bool graph[105][105];

ll solve(ll x, ll y)
{
	//cout << x << " " << y << endl;
	if(dp[x][y] != -1)
		return dp[x][y];
		
	if(x == n && y == m)
		return 1LL;
	
		
	ll ans = 0LL;
	
	for(ll i = 0; i < 2; i++)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		
		if(nx <= 0 || nx > n || ny <= 0 || ny > m || !graph[nx][ny]) continue;
		
		ans += solve(nx, ny);
	}
		
	return dp[x][y] = ans;
}

main()
{
	bool flag = false;
	ll t, num, aux;
	string s1;
	cin >> t;
	
	while(t--)
	{
		if(flag) cout << endl;
		memset(graph, true, sizeof graph);
		
		
		cin >> n >> m;
		cin.ignore();
		
		for(ll i = 0; i < n; i++)
		{
			getline(cin, s1);
			stringstream ss(s1);
			ss >> num;
			
			while(ss >> aux)
			{
				graph[num][aux] = false;
			}
		}
		
		memset(dp, -1, sizeof dp);
		
		cout << solve(1, 1) << endl;
		flag = true;
	}
}
