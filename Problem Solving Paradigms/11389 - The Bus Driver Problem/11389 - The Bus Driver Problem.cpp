#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

main()
{
	vector<ll>morning, afternoon;
	ll n, d, r, num;
	
	while(cin >> n >> d >> r && (n+d+r))
	{
		morning.clear();
		afternoon.clear();
		
		for(ll i = 0 ; i < n; i++){
			cin >> num;
			morning.push_back(num);
		}
		
		for(ll i = 0 ; i < n; i++){
			cin >> num;
			afternoon.push_back(num);
		}
		
		sort(morning.begin(), morning.end());
		sort(afternoon.rbegin(), afternoon.rend());
		
		ll pay = 0;
		for(ll i = 0 ; i < n; i++)
		{
			ll hours = morning[i] + afternoon[i];
			
			if(hours > d)
				pay += hours-d;
		}
		
		cout << pay*r << endl;
	}
}
