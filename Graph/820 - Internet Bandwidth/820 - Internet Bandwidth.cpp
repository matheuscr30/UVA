#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, parent[105], graph[105][105];
bool visited[105];

bool bfs(ll s, ll t)
{
	memset(visited, false, sizeof visited);
	queue<ll>q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty())
	{
		ll u = q.front();
		q.pop();
		
		for(ll v = 1; v <= n; v++)
		{
			if(!visited[v] and graph[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}			
		}
	}
	
	return (visited[t] == true);
}

ll EdmondKarps(ll s, ll t)
{
	ll maxflow = 0;
	
	while(bfs(s, t))
	{
		ll pathflow = INT_MAX;
		for(ll v = t; v != s; v = parent[v])
		{
			ll u = parent[v];
			pathflow = min(pathflow, graph[u][v]);
		}
		
		for(ll v = t; v != s; v = parent[v])
		{
			ll u = parent[v];
			graph[u][v] -= pathflow;
			graph[v][u] += pathflow;
		}
		
		maxflow += pathflow;
	}
	
	return maxflow;
}

main()
{
	ll c, u, v, p, cases=1, s, t;
	while(cin >> n && n)
	{
		memset(graph, 0, sizeof graph);
		
		cin >> s >> t >> c;
		
		for(ll i = 0 ; i < c; i++)
		{
			cin >> u >> v >> p;
			graph[u][v] += p; 
			graph[v][u] += p;
		}
		
		cout << "Network " << cases++ << endl;
		cout << "The bandwidth is " << EdmondKarps(s, t) << "." << endl;
		cout << endl;
	}
}
