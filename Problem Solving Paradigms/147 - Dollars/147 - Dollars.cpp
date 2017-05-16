#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long int ll;
ll tot, dp[15][30005];
vector<ll>vet;

ll solve(ll current, ll sum)
{
	if (current > 10 || sum < 0)
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
	stringstream ss;
	string str, aux;
	vet.pb(5);
	vet.pb(10);
	vet.pb(20);
	vet.pb(50);
	vet.pb(100);
	vet.pb(200);
	vet.pb(500);
	vet.pb(1000);
	vet.pb(2000);
	vet.pb(5000);
	vet.pb(10000);	
	
	ll n1, n2;
	memset(dp, -1, sizeof dp);
	
	while(scanf("%lld.%lld", &n1, &n2) && (n1+n2))
	{
		ss.clear();
		aux.clear();
		str.clear();
		aux = to_string(n2);
		
		ss << n1 << '.';
		if (aux.size() == 1)
			ss << '0' << n2;
		else
			ss << n2; 
		ss >> str;
		tot = n1*100 + n2;
		
		if (str.size() == 5)
			cout << " ";
		else if (str.size() == 4)
			cout << "  ";
		
		cout << str << setw(17) << solve(0, tot) << endl;
	}
}
