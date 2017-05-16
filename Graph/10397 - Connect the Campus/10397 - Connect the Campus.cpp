#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< pair<double, ii> >edges;
vector< ii > points;
ll parent[755], n;

void reset()
{
	edges.clear();
	points.clear();
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

double kruskal()
{
    ll pu, pv;
    double sum = 0;

    for (ll i = 0; i < edges.size(); i++)
    {
        pu = findset(edges[i].S.F);
        pv = findset(edges[i].S.S);

        if (pu != pv)
        {
			sum += edges[i].F; 
            UNION(pu, pv);
        }
    }
    
    return sum;
}

main()
{
	ll x, y, m, u, v;
	while(cin >> n)
	{
		reset();
		
		for(ll i = 0; i < n; i++)
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
			
			double dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
			edges.push_back( {dist, {u, v} } );
		}
		
		ll ex = kruskal();
		edges.clear();
		
		for(ll i = 1; i <= n; i++)
			for(ll j = i+1; j <= n; j++)
			{
				ll x1 = points[i-1].F, y1 = points[i-1].S;
				ll x2 = points[j-1].F, y2 = points[j-1].S;
			
				double dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
				edges.push_back( {dist, {i, j} } );
			}
			
		sort(edges.begin(), edges.end());
		double res = kruskal();
		
		cout << fixed << setprecision(2) << res << endl;
	}
}
