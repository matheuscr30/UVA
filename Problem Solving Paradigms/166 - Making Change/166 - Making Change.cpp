#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
vector<ll>vet;
ll buy, dp[10][1005];

ll solve(ll current, ll sum)
{
	if (current >= 6 || sum < 0)
		return INT_MAX;
	if (sum == 0)
		return 0;
	
	ll &re = dp[current][sum];
	if (re != -1)
		return re;
		
	ll ans, n1, n2;
	
	n1 = solve(current+1, sum) + solve(0, buy-sum);
	n2 = solve(current+1, sum-vet[current]+1) + solve(0, buy-sum-vet[current]);
	ans = min(n1, n2);
		
	return re = ans;
}

main()
{
	ll a, b, c, d, e, f;
	
	while(cin >> a >> b >> c >> d >> e >>f && (a+b+c+d+e+f))
	{
		vet.clear();
		for(ll i = 0; i < a; i++)
			vet.push_back(5);
		for(ll i = 0; i < b; i++)
			vet.push_back(10);
		for(ll i = 0; i < c; i++)
			vet.push_back(20);
		for(ll i = 0; i < d; i++)
			vet.push_back(50);
		for(ll i = 0; i < e; i++)
			vet.push_back(100);
		for(ll i = 0; i < f; i++)
			vet.push_back(200);
		
		ll in, fin;
		scanf("%lld.%lld", &in, &fin);
		buy = in*100 + fin;
		
		memset(dp, -1, sizeof dp);
		cout << setw(3) << solve(0, buy) << endl;
	}
}
