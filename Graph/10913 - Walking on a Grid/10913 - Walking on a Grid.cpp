#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, k, grafo[80][80], dp[80][80][8][5];
bool can;

//0 - Veio da Esquerda
//1 - Veio da Direita
//2 - Veio de Cima
ll solve(ll x, ll y, ll quan, ll last)
{
	//cout << x << " " << y << " " << quan << " " << last << endl; 
	if(quan > k || (quan == k & grafo[x][y] < 0))
		return INT_MIN;
		
	if(x == n && y == n && quan <= k){
		can = true;
		return 0LL;
	}
	
	if(dp[x][y][quan][last] != -1)	
		return dp[x][y][quan][last];
	
	ll ans = INT_MIN;
	ll nquan = (grafo[x][y] < 0 ? quan+1 : quan);
	
	if(last == 1)
	{
		if(x+1 <= n)
			ans = max(ans, solve(x+1, y, nquan, 2) + grafo[x+1][y]);
		
		if(y+1 <= n)
			ans = max(ans, solve(x, y+1, nquan, 1) + grafo[x][y+1]);
	}
	else if(last == 0)
	{
		if(x+1 <= n)
			ans = max(ans, solve(x+1, y, nquan, 2) + grafo[x+1][y]);
		
		if(y-1 >= 1)
			ans = max(ans, solve(x, y-1, nquan, 0) + grafo[x][y-1]);
		
	}
	else
	{
		if(x+1 <= n)
			ans = max(ans, solve(x+1, y, nquan, 2) + grafo[x+1][y]);
		
		if(y-1 >= 1)
			ans = max(ans, solve(x, y-1, nquan, 0) + grafo[x][y-1]);
		
		if(y+1 <= n)
			ans = max(ans, solve(x, y+1, nquan, 1) + grafo[x][y+1]);
	}
		
	return dp[x][y][quan][last] = ans;
}

main()
{
	ll cases = 1;
	while(cin >> n >> k && (n+k))
	{
		can = false;
		memset(grafo, 0, sizeof grafo);
		
		for(ll i = 1; i <= n; i++)
			for(ll j = 1; j <= n; j++)
				cin >> grafo[i][j];
				
		memset(dp, -1, sizeof dp);
		ll res = solve(1, 1, 0, 2);
		
		cout << "Case " << cases++ << ": ";
		if(!can)
			cout << "impossible" << endl;
		else
			cout << res+grafo[1][1] << endl;
	}
}
