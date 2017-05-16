#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
vector< vector<ll> >graph(5005);
vector< ll >menores, maiores;
ll dist[5005], n;

ll bfs(ll s)
{
	ll last;
	for(ll i = 0; i <= n; i++)
		dist[i] = INT_MAX;
	
	queue< ll >pq;
	pq.push( s );
	dist[s] = 0;
	
	while(!pq.empty())
	{
		ll u = pq.front();
		pq.pop();
		last = u;
	
		for(ll i = 0; i < graph[u].size(); i++)
		{
			ll v = graph[u][i];
			
			if(dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				pq.push( v );
			}
		}
	}
	
	return dist[last];
}

main()
{
	ll num, q;
	
	while(cin >> n)
	{
		menores.clear();
		maiores.clear();
		for(ll i = 1; i <= n; i++)
			graph[i].clear();
		
		for(ll i = 1; i <= n; i++)
		{
			cin >> q;
			for(ll j = 0; j < q; j++)
			{
				cin >> num;
				graph[i].push_back(num);
				graph[num].push_back(i);
			}
		}
		
		ll menor = INT_MAX, maior = 0;
		for(ll i = 1; i <= n; i++)
		{
			ll di = bfs(i);
			
			if(di < menor){
				menores.clear();
				menores.push_back(i);
				menor = di;
			}
			else if(di == menor)
				menores.push_back(i);
				
			if(di > maior){
				maiores.clear();
				maiores.push_back(i);
				maior = di;
			}
			else if(di == maior)
				maiores.push_back(i);
		}
		
		cout << "Best Roots :";
		for(ll i = 0; i < menores.size(); i++)
			cout << " " << menores[i];
		cout << endl;
		
		cout << "Worst Roots :";
		for(ll i = 0; i < maiores.size(); i++)
			cout << " " << maiores[i];
		cout << endl;
	}
}
