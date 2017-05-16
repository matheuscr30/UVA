#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, m, graph[75][75], graph2[75][75];
bool visited[75];

ll send(ll s, ll t, ll minn)
{
	visited[s] = true;
	
	if(s == t) return minn;
	for(ll i = 1; i <= n; i++){
		if(!visited[i] && graph[s][i] > 0){
			if(ll sent = send(i, t, min(minn, graph[s][i])))
			{
				graph[s][i] -= sent;
				graph[i][s] += sent;
				return sent;
			}
		}
	}
	return 0;
}

void dfs(ll u)
{
	visited[u] = true;
	for(ll i = 1; i <= n; i++)
		if(!visited[i] && graph[u][i] > 0)
			dfs(i);
}

main()
{
	ll u, v, c, s, t;
	while(cin >> n >> m && (n+m))
	{
		s = 1; t = 2;
		memset(graph, false, sizeof graph);
		memset(graph2, false, sizeof graph2);
		
		for(ll i = 0 ; i < m; i++)
		{
			cin >> u >> v >> c;
			graph[u][v] += c; 
			graph[v][u] += c;
			graph2[u][v] += c;
			graph2[v][u] += c;
		}
		
		ll res = 0;
		memset(visited, false, sizeof visited);
		while(ll sent = send(s, t, INT_MAX))
		{
			res += sent;
			memset(visited, false, sizeof visited);
		}
		//cout << res << endl;
		
		memset(visited, false, sizeof visited);
		dfs(s);
		
		for(ll i = 1; i <= n; i++)
			for(ll j = 1; j <= n; j++)	
				if(visited[i] && !visited[j] && graph2[i][j] > 0)
					cout << i << " " << j << endl;
		cout << endl;
		
	}
}
