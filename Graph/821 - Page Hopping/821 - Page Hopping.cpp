#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll dist[105][105];

main()
{
	ll n1, n2, cases=1;
	stringstream ss;
	string str;
	
	while(getline(cin, str) && str != "0 0")
	{
		ss.clear();
		ss << str;
		ll best = -1;
		
		for(ll i = 1; i < 105; i++)
			for(ll j = 1; j < 105; j++)
				dist[i][j] = i == j ? 0 : INT_MAX;
		
		while(ss >> n1 >> n2 && (n1+n2))
		{
			dist[n1][n2] = 1;
			best = max(best, max(n1, n2));
		}
		
		ll sum1, sum2;
		sum1 = sum2 = 0;
		for(ll k = 1; k <= best; k++)
			for(ll i = 1; i <= best; i++)
				for(ll j = 1; j <= best; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
		for(ll i = 1; i <= best; i++)
				for(ll j = 1; j <= best; j++){
					if(dist[i][j] != INT_MAX and dist[i][j] != 0)
						sum1++, sum2+=dist[i][j];
				}		
				
		cout << "Case " << cases++ << ": average length between pages = ";
		cout << fixed << setprecision(3) << (double)sum2/sum1 << " clicks" << endl;
		
	}
}
