#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll ;
ll n, buy, dp[105][20005];
vector<ll>vet;

ll solve(ll current, ll sum)
{
	if (sum == 0)
		return 0;
	if (current == n || sum < 0)
		return INT_MAX;
	
	ll &re = dp[current][sum];
	if (re != -1)
		return re;
		
	ll ans = min(solve(current+1, sum), solve(current+1, sum-vet[current]) + 1);
		
	return re = ans;
}

main()
{
	ll t, num;
	cin >> t;
	
	while(t--)
	{
		vet.clear();
		cin >> buy;
		cin >> n;
		
		for (ll i = 0 ; i < n; i++){
			cin >> num;
			vet.push_back(num);
		}
		
		memset(dp, -1, sizeof(dp));
		
		ll result, res;
		for(ll i = buy; i <= buy + 10000; i++){
			res = solve(0, i);
			
			//	cout << res << endl;
			
			if (res != INT_MAX)
			{
				result = i;
				break;
			}
		}
		
		cout << result << " " << res << endl;
	}
}
