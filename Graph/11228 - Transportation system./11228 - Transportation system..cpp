#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< pair< double , ii > >arestas;
vector< ii >vertices;
ll n, r, parent[1005];
double roads, railroads, states;

void reset()
{
	arestas.clear();
	vertices.clear();
	roads = railroads = states = 0;
	
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

void kruskal()
{
    ll pu, pv;

    for (ll i = 0; i < arestas.size(); i++)
    {
        pu = findset(arestas[i].S.F);
        pv = findset(arestas[i].S.S);

        if (pu != pv)
        {
			if(arestas[i].F <= r)
				roads += arestas[i].F;
			else
				railroads += arestas[i].F, states++;
            UNION(pu, pv);
        }
    }
}

main()
{
	ll t, x, y, cases=1;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> r;
		reset();
		
		for(ll i = 0 ; i < n; i++)
		{
			cin >> x >> y;
			vertices.push_back( {x, y} );
		}
		
		for(ll i = 0; i < n; i++)
			for(ll j = i+1; j < n; j++)
			{
				double dist = (vertices[i].F - vertices[j].F)*(vertices[i].F - vertices[j].F);
				dist += (vertices[i].S - vertices[j].S)*(vertices[i].S - vertices[j].S);
				dist = sqrt(dist);
				
				arestas.push_back( {dist, {i, j} } ); 
			}
			
		sort(arestas.begin(), arestas.end());
		kruskal();
		
		cout << "Case #" << cases++ << ": " << states+1 << " " << round(roads) << " " << round(railroads) << endl;
	}
}
