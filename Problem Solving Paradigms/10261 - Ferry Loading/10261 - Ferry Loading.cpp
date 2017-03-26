#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector<ll>vet;
ll length;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll t, num;
	cin >> t;
	
	while(t--)
	{
		vet.clear();
		cin >> length;
		
		while(cin >> num && num)
		{
			vet.push_back(num);
		}
		
		ll res = solve(0, 
	}
}
