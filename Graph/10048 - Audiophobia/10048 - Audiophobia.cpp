#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
ll dist[105][105];

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll c, s, q, u, v, p, cases=1;
	bool flag = false;
	
	while(cin >> c >> s >> q && (c+s+q))
	{
		if (flag)	
			cout << endl;
		
		for(ll i = 0 ; i <= c; i++)
			for(ll j = 0 ; j <= c; j++)
				dist[i][j] = (i == j ? 0 : INT_MAX);
				
		for(ll i = 0 ; i < s; i++)
		{
			cin >> u >> v >> p;
			dist[u][v] = min(dist[u][v], p);
			dist[v][u] = dist[u][v];
		}
		
		for(ll k = 1; k <= c; k++)
			for(ll i = 1; i <= c; i++)
				for(ll j = 1; j <= c; j++)
					dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
			
		cout << "Case #" << cases++ << endl;		
		while(q--)
		{
			cin >> u >> v;
			
			if(dist[u][v] == INT_MAX)
				cout << "no path" << endl;
			else
				cout << dist[u][v] << endl;
		}
		
		flag = true;
	}
}
