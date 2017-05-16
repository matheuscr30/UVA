#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< ii >points;
vector< pair<double, ii> >edges;
ll parent[505], s, p;
double res;

void reset()
{
	for(ll i = 0; i <= p; i++)
		parent[i] = i;
	
	points.clear();
	edges.clear();
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

void kruskal()
{
    ll pu, pv, cont = 0;
    res = 0;

    for (ll i = 0; i < edges.size(); i++)
    {
        pu = findset(edges[i].S.F);
        pv = findset(edges[i].S.S);

        if (pu != pv)
        {
			if(cont == p-s)
				break;
			res = max(res, edges[i].F);
			
            UNION(pu, pv);
            cont++;
        }
    }
}

main()
{
	ll n, x, y;
	cin >> n;
	
	while(n--)
	{
		cin >> s >> p;
		reset();
		
		for(ll i = 0 ; i < p; i++)
		{
			cin >> x >> y;
			points.push_back( {x, y} );
		}
		
		for(ll i = 0 ; i < p; i++)
			for(ll j = i+1; j < p; j++)
			{
				double dist = sqrt( pow(points[i].F - points[j].F, 2) + pow(points[i].S - points[j].S, 2));
				edges.push_back( {dist, {i, j} } );
			}
			
		sort(edges.begin(), edges.end());
		
		kruskal();
		cout << fixed << setprecision(2) << res << endl;
	}
}
