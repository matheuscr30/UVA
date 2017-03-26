#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

main()
{
	ll n, k;
	
	while(cin >> n >> k)
	{
		ll extra = 0, tot = n;
		while(n > 0 && n >= k)
		{
			ll div = n/k;
			extra += div;
			
			n -= k*div;
			n += div;
			
			//cout << div << " " << extra << " " << n << endl;
		}
		
		cout << tot+extra << endl;
	}
}
