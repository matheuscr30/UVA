#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< pair<ll, ii> >edges, tr;
vector< ii > points, MST;
ll parent[755], n;

void reset()
{
	edges.clear();
	points.clear();
	MST.clear();
	tr.clear();
	
	for(ll i = 0 ; i <= n; i++)
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

ll kruskal(ll ini)
{
    ll pu, pv;
    ll sum = 0;

    for (ll i = 0; i < edges.size(); i++)
    {
        pu = findset(edges[i].S.F);
        pv = findset(edges[i].S.S);

        if (pu != pv)
        {
			if(ini != 0)
				MST.push_back( {edges[i].S.F, edges[i].S.S } );
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
	bool flag = false;
	ll t, m, x, y, u, v;
	cin >> t;
	
	while(t--)
	{
		if(flag)
			cout << endl;
		cin.ignore();
		cin.ignore();
		
		cin >> n;
		reset();
		
		for(ll i = 0 ; i < n; i++)
		{
			cin >> x >> y;
			points.push_back( {x, y} );
		}
		
		cin >> m;
		
		for(ll i = 0; i < m; i++)
		{
			cin >> u >> v;
			ll x1 = points[u-1].F, y1 = points[u-1].S;
			ll x2 = points[v-1].F, y2 = points[v-1].S;
			
			ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
			edges.push_back( {dist, {u, v} } );
		}
		
		ll res = kruskal(0);
		edges.clear();
		
		if(res != INT_MAX)
			cout << "No new highways need" << endl;
		else
		{
			for(ll i = 1 ; i <= n; i++)
				for(ll j = i+1; j <= n; j++)
				{
					ll x1 = points[i-1].F, y1 = points[i-1].S;
					ll x2 = points[j-1].F, y2 = points[j-1].S;
			
					ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
					edges.push_back( {dist, {i, j} } );
				}
			sort(edges.begin(), edges.end());
			kruskal(1);
			
			for(ll i = 0; i < MST.size(); i++)
				cout << MST[i].F << " " << MST[i].S << endl; 
		}
		
		flag = true;
	}
} 
