#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
ll n, m, parent[105];
pair<ll, ii> excep;
vector< pair<ll, ii> >edges, MST;

void reset()
{
	for(ll i = 0; i <= n; i++)
		parent[i] = i;
}

ll findset(ll x)
{
    if (x != parent[x])
        parent[x] = findset(parent[x]);

    return parent[x];
}

void UNION(ll x, ll y)
{
    parent[x] = parent[y];
}

ll kruskal(bool pdt)
{
    ll pu, pv;
    ll sum = 0;

    for (ll i = 0; i < edges.size(); i++)
    {
		if(edges[i].F == excep.F and edges[i].S.F == excep.S.F and edges[i].S.S == excep.S.S)
			continue;
        pu = findset(edges[i].S.F);
        pv = findset(edges[i].S.S);

        if (pu != pv)
        {
			if(pdt == true)
				MST.push_back(edges[i]);
			sum += edges[i].F; 
            UNION(pu, pv);
        }
    }
    
    pu = findset(1);
    for(ll i = 2; i <= n; i++)
	{
		pv = findset(i);
		if (pu != pv)
			return INT_MAX;
	}
    
    return sum;
}

main()
{
	ll t, u, v, p;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		reset();
		edges.clear();
		MST.clear();
		
		for(ll i = 0; i < m; i++)
		{
			cin >> u >> v >> p;
			edges.push_back( {p, {u, v} } );
		}
		
		sort(edges.begin(), edges.end());
		excep = {-1, {-1, -1} };
		ll best = kruskal(true);
		ll second = INT_MAX;
		
		for(ll i = 0; i < MST.size(); i++)
		{
			reset();
			excep = MST[i];
			second = min(second, kruskal(false));
		}
		
		cout << best << " " << second << endl;
	}
}
