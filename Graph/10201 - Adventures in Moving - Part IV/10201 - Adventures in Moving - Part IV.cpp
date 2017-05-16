#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
bool can;
ll dp[105][205], dis, precos[105], pesos[105], n;

ll solve(ll current, ll fuel)
{
//	cout << current << " " << fuel << endl;
	if(fuel < 0 || current > n) return INT_MAX;
	
	if(dp[current][fuel] != -1)
		return dp[current][fuel];
		
	if(current == n && fuel >= 100){
		return dp[current][fuel] = 0LL;
		can = true;
	}
	
	ll ans = INT_MAX;
		
	if(current == 0)
	{
		for(ll i = current+1; i <= n && pesos[i] <= fuel; i++)
			ans = min(ans, solve(i, fuel - pesos[i]));
	}
	else{
		for(ll i = current+1; i <= n && (pesos[i] - pesos[current] <= 200); i++)
		{
			for(ll j = 0 ;  j + fuel <= 200; j++)
			{
				ans = min(ans, solve(i, j + fuel - (pesos[i] - pesos[current])) + precos[current]*j);
			}
		}
	}	
	return dp[current][fuel] = ans;
}

main()
{
	bool flag = false;
	ll t, dist, x ,price;
	cin >> t;
	
	while(t--)
	{
		n = 1;
		can = false;
		if(flag) cout << endl;
	
		cin >> dist;
		getchar();
		dis = dist;
		
		string str;
		while(getline(cin, str) && str.size() > 1)
		{
			stringstream ss(str);
			ss >> x >> price;

			pesos[n] = x;
			precos[n] = price;
			n++;
		}
		
		pesos[n] = dist;
		pesos[0] = 0;
		memset(dp, -1, sizeof dp);
		
		ll res = solve(0, 100);
		
		if(res != INT_MAX)
			cout << res << endl;
		else
			cout << "Impossible" << endl;
			
		flag = true;
	}
}
