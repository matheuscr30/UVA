#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
vector<ll> vet;
ll tot, dp[25][10005];

ll solve(ll current, ll sum)
{
	if (current > 20 || sum < 0)
		return 0LL;
	if (sum == 0)	
		return 1LL;
		
	if (dp[current][sum] != -1)
		return dp[current][sum];
		
	ll ans = solve(current+1, sum) + solve(current, sum-vet[current]);
		
	return dp[current][sum] = ans;
}

main()
{
	for (ll i = 1; i <= 21; i++)
		vet.push_back(i*i*i);
		
	memset(dp, -1, sizeof dp);
	
	while(cin >> tot)
	{
		cout << solve(0, tot) << endl;
	}
}
