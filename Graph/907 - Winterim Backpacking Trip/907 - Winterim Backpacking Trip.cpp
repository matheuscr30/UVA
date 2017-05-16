#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, k, dp[650][350];
vector<ll>vet;

ll solve(ll current, ll quant)
{
	//cout << current << " " << quant << endl;
	if(current == n+1)
	{
		if(quant == k+1)
			return 0;
		else
			return -1;
	}
	
	if(dp[current][quant] != -1)
		return dp[current][quant];
		
	ll ans = INT_MAX;
	ll sum = 0;
	for(ll i = current; i < n+1; i++)
	{
		sum += vet[i];
		
		ll res = solve(i+1, quant+1);
		
		if(res != -1)
			ans = min(ans, max(sum, solve(i+1, quant+1)));
	}
		
	return dp[current][quant] = ans;
}

main()
{
	ll num;
	while(cin >> n >> k)
	{
		memset(dp, -1, sizeof dp);
		vet.clear();
		
		for(ll i = 0 ; i < n+1; i++)
		{
			cin >> num;
			vet.push_back(num);
		}
		
		cout << solve(0, 0) << endl;
	}
}
