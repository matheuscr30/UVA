#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
vector<ll>vet;
ll n, dp[205][205][205], d, m;

ll solve(ll current, ll sum, ll quan)
{
	if (current == n)
	{
		if (quan != m || sum%d != 0)
			return 0LL;
		else
			return 1LL;
	}
	
	if (quan == m)
	{
		if (sum%d != 0)
			return 0LL;
		else 
			return 1LL;
	}
	
	if(dp[current][sum][quan] != -1)
		return dp[current][sum][quan];
		
	ll ans = solve(current+1, sum%d, quan);
	
	if (quan+1 <= m)
		ans += solve(current+1, (sum+vet[current])%d, quan+1);
		
	return dp[current][sum][quan] = ans;
}

main()
{
	ll q, num, cases=1;
	
	while(cin >> n >> q && (n+q))
	{
		vet.clear();
		for (ll i = 0 ; i < n; i++){
			cin >> num;
			vet.push_back(num);
		}
		
		cout << "SET " << cases++ << ":" << endl;
		for (ll i = 1; i <= q; i++)
		{
			cin >> d >> m;
			memset(dp, -1, sizeof dp);
			cout << "QUERY " << i << ": " << solve(0, 0 ,0) << endl;
		}
		
	}
}
