#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll tam, graph[125][125];
bool visited[125];

ll send(ll s, ll t, ll minn)
{
	visited[s] = true;
	
	if(s == t) return minn;
	for(ll i = 1; i <= tam; i++){
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

main()
{
	ll m, w ,u, v, c;
	
	while(cin >> m >> w && (m+w))
	{
		tam = 2*m;
		memset(graph, 0, sizeof graph);
		
		graph[1][m+1] = graph[m][m+m] = INT_MAX;
		for(ll i = 1; i <= m-2; i++)
		{
			cin >> u >> c;
			graph[u][m+u] += c;
		}
		
		for(ll i = 1; i <= w; i++)
		{
			cin >> u >> v >> c;
			graph[m+u][v] += c;
			graph[m+v][u] += c;
		}
		
		ll res = 0;
		memset(visited, false, sizeof visited);
		
		while(ll sent = send(1, m+m, INT_MAX))
		{
			res += sent;
			memset(visited, false, sizeof visited);
		}
		
		cout << res << endl;
	}
}
