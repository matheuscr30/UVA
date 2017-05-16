#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll k, n, dp[35], path[35];
vector< vector< ll > >boxes(35);
bool graph[35][35];

ll solve(ll current)
{
	if(dp[current] != -1)
		return dp[current];
	
	ll ans = 0;
	
	for(ll i = 1; i <= k; i++)
	{
		if(i == current or !graph[current][i]) continue;
		
		ll h = solve(i) + 1;
		if(h > ans)
		{
			ans = h;
			path[current] = i;
		}
	}		
	
	return dp[current] = ans;
}

void reset()
{
	for(ll i = 0; i <= k; i++)
	{
		boxes[i].clear();
		dp[i] = path[i] = -1;
		
		for(ll j = 0 ; j <= k; j++)
			graph[i][j] = false;
	}
}

main()
{
	ll num;
	while(cin >> k >> n)
	{
		reset();
		for(ll i = 1; i <= k; i++)
		{
			for(ll j = 0 ; j < n; j++)
			{
				cin >> num;
				boxes[i].push_back(num);
			}
			sort(boxes[i].begin(), boxes[i].end());
		}
		
		for(ll i = 1; i <= k; i++)
		{
			graph[0][i] = true;
			for(ll l = 1; l <= k; l++)
			{
				graph[i][l] = true;
				for(ll j = 0 ; j < n; j++)
				{
					if(boxes[i][j] >= boxes[l][j]){
						graph[i][l] = false;
						break;
					}
				}
			}
		}
		
		cout << solve(0) << endl;
		
		bool flag = false;
		for(ll i = path[0]; i != -1; i = path[i])
		{
			if(flag)
				cout << " ";
			cout << i;
			flag = true;
		}
		cout << endl;
	}
}
