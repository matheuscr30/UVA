#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll winds[15][1005], n, dp[15][1005];

ll solve(ll wind, ll current)
{
	//cout << wind << " " << current << endl;
	if (current == n)
		if (wind == 9) return 0LL;
		else return INT_MAX;
	
	if(dp[wind][current] != -1)
		return dp[wind][current];
		
	ll ans = INT_MAX;
	
	if(current == 0)
		ans = min(ans, solve(wind - 1, current + 1) + 60 - winds[wind][current]);
	else if (n-current+1 == 10-wind)
		ans = min(ans, solve(wind + 1, current + 1) + 20 - winds[wind][current]);
	else
	{
		//SOBE
		if (wind > 0)
			ans = min(ans, solve(wind - 1, current + 1) + 60 - winds[wind][current]);
		//DESCE
		if(wind + 1 != 9)
			ans = min(ans, solve(wind + 1, current + 1) + 20 - winds[wind][current]);
		//RETO
		ans = min(ans, solve(wind, current+1) + 30 - winds[wind][current]);
	}
	//cout << 'v' << ans << endl;
		
	return dp[wind][current] = ans;
}

main()
{
	ll t, x;
	cin >> t;
	
	while(t--)
	{
		cin >> x;
		n = x/100;
		
		for(ll i = 0; i < 10; i++){
			for(ll j = 0; j < x/100; j++){
				cin >> winds[i][j];
				//scout << winds[i][j];
			}
			//cout << endl;
		}		
		memset(dp, -1, sizeof dp);
		cout << solve(9, 0) << endl << endl;
	}
}
