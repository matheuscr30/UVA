#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< pair<ll, ii> >edges;
vector< ll > pos;
ll n, m, parent[105], excep;

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
		if(excep == i)
			continue;
        pu = findset(edges[i].S.F);
        pv = findset(edges[i].S.S);

        if (pu != pv)
        {
			if(pdt == true)
				pos.push_back(i);
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
	ll t, u, v, p, cases=1;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		edges.clear();
		pos.clear();
		reset();
		
		for(ll i = 0 ; i < m; i++)
		{
			cin >> u >> v >> p;
			edges.push_back( {p, {u, v} } );
		}
		
		sort(edges.begin(), edges.end());
		excep = -1;
		ll best = kruskal(true);
		ll second = INT_MAX;
		
		for(ll i = 0; i < pos.size(); i++)
		{
			excep = pos[i];
			reset();
			second = min(second, kruskal(false));
		}
		
		cout << "Case #" << cases++ << " : "; 
		if (best == INT_MAX)
			cout << "No way" << endl;
		else if (second == INT_MAX)
			cout << "No second way" << endl;
		else
			cout << second << endl;
		
	}
}
