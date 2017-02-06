#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector< pair<ll, ii> >edges;
map<string, ll> hashi;
ll s, c, parent[405];

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

ll kruskal()
{
    ll pu, pv;
    ll sum = 0;

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
    
    pu = findset(0);
    for(ll i = 1; i < s; i++)
	{
		pv = findset(i);
		if (pu != pv)
			return INT_MAX;
	}
    
    return sum;
}

main()
{
	string s1, s2;
	ll p;
	while(cin >> s >> c && (s+c))
	{
		hashi.clear();
		edges.clear();
		
		for(ll i = 0; i < s; i++)
		{
			cin.ignore();
			cin >> s1;
			hashi[s1] = i;
			parent[i] = i;
		}
		
		for(ll i = 0; i < c; i++)
		{
			cin.ignore();
			cin >> s1 >> s2 >> p;
			
			edges.push_back( {p, {hashi[s1], hashi[s2]} } );
		}
		cin.ignore();
		cin >> s1;
		
		sort(edges.begin(), edges.end());
		
		ll best = kruskal();
		
		if(best == INT_MAX)
			cout << "Impossible" << endl;
		else
			cout << best << endl;
	}
}
