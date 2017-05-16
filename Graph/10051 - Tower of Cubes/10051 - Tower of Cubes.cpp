#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, cubes[505][105], dp[505][105];

ll again(ll pos)
{
	if(pos == 0)
		return 1;
	else if(pos == 1)
		return 0;
	else if(pos == 2)
		return 3;
	else if(pos == 3)
		return 2;
	else if(pos == 4)
		return 5;
	else if(pos == 5)
		return 4;
}

ll solve(ll current, ll last)
{	
	if(current == -1 || current == 0)
		return 0LL;
	
	if(dp[current][last] != -1)
		return dp[current][last];
		
	ll ans = solve(current+1, last);

	for(ll i = 0; i < 6; i++)
	{
		if(cubes[current-1][i] == last)
			ans = max(ans, solve(current-1, cubes[current-1][again(i)]) + 1 );
	}
		
	return dp[current][last] = ans;
}

main()
{
	trans[0] = "front";
	trans[1] = "back";
	trans[2] = "left";
	trans[3] = "right";
	trans[4] = "top";
	trans[5] = "bottom";
	
	ll num, cases=1;
	while(cin >> n && n)
	{
		for(ll i = 0; i < n; i++)
		{
			for(ll j = 0; j < 6; j++)
			{
				cin >> num;
				cubes[i][j] = num;
			}
		}
		
		ll maior = 0;
		memset(dp, -1, sizeof dp);
		for(ll i = 0; i < 6; i++)
		{
			ll res = solve(n-1, cubes[0][i]);
			maior = max(maior, res);
		}
		
		cout << maior << endl;
	}
}
