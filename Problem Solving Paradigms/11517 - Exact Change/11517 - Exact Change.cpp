#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll buy, n, first, dp[105][10005][105];
bool flag;
vector<ll>vet;

ll solve(ll current, ll sum, ll cont)
{
	if (sum >= buy){
		first = min(first, cont);
		return sum;
	}
		
	if (current == n)
		return INT_MAX;
		 
	if (dp[current][sum][cont] != -1)
		return dp[current][sum][cont];
		
	ll ans = solve(current+1, sum, cont);
	
	ans = min(ans, solve(current+1, sum+vet[current], cont+1));
		
	return dp[current][sum][cont] = ans;
}

main()
{
	ll t, num;
	cin >> t;
	
	while(t--)
	{
		cin >> buy;
		cin >> n;
		
		for(ll i = 0 ; i < n; i++){
			cin >> num;
			vet.push_back(num);
		}
		//sort(vet.begin(), vet.end());
		memset(dp, -1, sizeof dp);
		first = 10000;
		ll res = solve(0, 0, 0);
		cout << res << " " << first << endl;
	}
}
