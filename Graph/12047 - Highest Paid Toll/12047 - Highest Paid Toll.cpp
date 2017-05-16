#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< vector<ii> > grafo(10005);
bool visited[10005];
ll n;

ll dijsktra(ll orig, ll dest, ll p)
{
	ll res = -1;
	memset(visited, false, sizeof visited);
	priority_queue< pair<ll, ii> , vector< pair<ll, ii> >, greater< pair<ll, ii > > >pq;
	
	pq.push( {0, {0, orig} } );
	
	while(!pq.empty())
	{
		ll dis = pq.top().F;
		ll maior = pq.top().S.F;
		ll u = pq.top().S.S;
		pq.pop();
		
		visited[u] = true;
		
		if(u == dest && dis <= p)
		{
			res = max(res, maior);
			visited[u] = false;
		}
		
		for(ll i = 0; i < grafo[u].size(); i++)
		{
			ll ndist = grafo[u][i].S;
			ll v = grafo[u][i].F;
			
			if(!visited[v])
			{
				pq.push( {dis+ndist, { max(maior, ndist), v } } );
			}
		}
	}
	
	return res;
}

main()
{
	ll t, m, s, d, p, u, v, c;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m >> s >> d >> p;
		
		for(ll i = 0 ; i <= n; i++)
			grafo[i].clear();
		
		for(ll i = 0 ; i < m; i++)
		{
			cin >> u >> v >> c;
			grafo[u].push_back({v, c});
		}
		
		ll res =  dijsktra(s, d, p);
		cout  << res << endl;
	}
}
