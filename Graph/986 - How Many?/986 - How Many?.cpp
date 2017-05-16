#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, r, k, dp[50][25][5][25];
ll dx[] = {1, 1}, dy[] = {1, -1};

ll solve(ll x, ll y, ll last, ll peaks)
{
	if(peaks > r || y > n || y < 0 || x < 0 || x > 2*n)
		return 0LL;
	//cout << x << " " << y << " " << last << " " << peaks << endl;
	if(x == 2*n && y == 0 && peaks == r)
		return 1LL;
	
	if(dp[x][y][last][peaks] != -1)
		return dp[x][y][last][peaks];
		
	ll ans = 0LL;
	
	if(y == k)
	{
		if(last == 0)
		{
			ans += solve(x+1, y-1, 1, peaks+1);
			ans += solve(x+1, y+1, 0, peaks);
		}
		else{
			ans += solve(x+1, y+1, 0, peaks);
			ans += solve(x+1, y-1, 1, peaks);
		}
		dp[x][y][last][peaks] = ans;
		return dp[x][y][last][peaks];
	}
	
	ans += solve(x+1, y-1, 1, peaks);
	ans += solve(x+1, y+1, 0, peaks);
		
	return dp[x][y][last][peaks] = ans;
}

main()
{
	while(cin >> n >> r >> k)
	{
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0, 4, 0) << endl;
	}
}
