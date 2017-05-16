#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
ll m, s, dp[45][305][305];
vector< pair<ll, ll> >vet;

ll solve(ll current, ll sum1, ll sum2)
{
	double raiz = sqrt(sum1*sum1 + sum2*sum2);
	if (raiz == s)
		return 0;
	if (current == m || raiz > s)
		return INT_MAX;
	
	ll &re = dp[current][sum1][sum2];
	if (re != -1)
		return re;
		
	ll ans = min(solve(current+1, sum1, sum2), solve(current, sum1+vet[current].F, sum2+vet[current].S)+1);
	
	return re = ans;
}

main()
{
	ll n, a, b;
	cin >> n;
	
	while(n--)
	{
		vet.clear();
		cin >> m >> s;
		
		for(ll i = 0 ; i < m; i++){
			cin >> a >> b;
			vet.push_back( {a, b} );
		}
		
		memset(dp, -1, sizeof dp);
		ll res = solve(0, 0, 0);
		
		if (res >= INT_MAX)
			cout << "not possible" << endl;
		else
			cout << res << endl;
	}
}
