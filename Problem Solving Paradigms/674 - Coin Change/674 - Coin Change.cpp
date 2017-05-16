#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll tot, dp[7][10005];
vector<ll>vet;

ll solve(ll current, ll sum)
{
	if (current > 4 || sum < 0)
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
	vet.push_back(1);
	vet.push_back(5);
	vet.push_back(10);
	vet.push_back(25);
	vet.push_back(50);
	memset(dp, -1, sizeof dp);
	
	while(cin >> tot)
	{
		cout << solve(0, tot) << endl;
	}
}
