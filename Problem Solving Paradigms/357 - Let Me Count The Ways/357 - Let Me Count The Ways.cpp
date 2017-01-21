#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tot, dp[30005][10];
vector<ll>vet;

ll solve(ll sum, ll current)
{
	if (current > 4 || sum < 0)
		return 0LL;
	if (sum == 0)
		return 1LL;
		
	if (dp[sum][current] != -1)
		return dp[sum][current];
		
	ll ans = solve(sum, current+1) + solve(sum - vet[current], current);
	
	return dp[sum][current] = ans;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vet.push_back(1);
	vet.push_back(5);
	vet.push_back(10);
	vet.push_back(25);
	vet.push_back(50);
	memset(dp, -1, sizeof dp);
	
	while(cin >> tot)
	{
		ll res = solve(tot,0);
		
		if (res == 1)
			cout << "There is only " << res << " way to produce " << tot << " cents change." << endl;
		else
			cout << "There are " << res <<" ways to produce " << tot << " cents change." << endl;
	}
}
