#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long int ll;
ll m, n, dp[105][40300], MAX;
vector<ll>price, favour;

ll solve(ll current, ll sum)
{
	if (current == n)
	{
		if ((sum > 2000 && sum <= m+200) || (sum <= m))
			return 0LL;
		else
			return INT_MIN;
	}
		
	if (dp[current][sum] != -1)
		return dp[current][sum];
		
	ll ans = solve(current+1, sum);
	
	ll nsum = sum+price[current];
	if (nsum <= m+200)
		ans = max(ans, solve(current+1, nsum) + favour[current]);
		
	return dp[current][sum] = ans;
}

main()
{
	ll num1, num2;
	while(cin >> m >> n)
	{
		price.clear();
		favour.clear();
		for (ll i = 0 ; i < n; i++){
			cin >> num1 >> num2;
			price.push_back(num1);
			favour.push_back(num2);
		}
		
		memset(dp, -1, sizeof dp);
		MAX = (m+200) - (2001-m);
		cout << solve(0, 0) << endl;
	}
}
