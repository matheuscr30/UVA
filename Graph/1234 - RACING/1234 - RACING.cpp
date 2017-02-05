#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< pair<ll, ii > >grafo;
ll n, m, parent[10005], total;

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

    for (ll i = 0; i < grafo.size(); i++)
    {
        pu = findset(grafo[i].second.first);
        pv = findset(grafo[i].second.second);

        if (pu != pv)
        {
            UNION(pu, pv);
        }
        else
			total += grafo[i].first;
    }
}

void reset()
{
	total = 0;
	grafo.clear();
	for(ll i = 0 ; i <= n; i++)
		parent[i] = i;
}

main()
{
	ll t, u, v, p;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		reset();
		for(ll i = 0 ; i < m; i++)
		{
			cin >> u >> v >> p;
			grafo.push_back( {p, {u, v}} );
		}
		sort(grafo.rbegin(), grafo.rend());
		
		kruskal();
		cout << total << endl;
	}
}
