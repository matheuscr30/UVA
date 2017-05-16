#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, m, tam, graph[210][210];
bool visited[210];

ll send(ll s, ll t, ll minn)
{
	visited[s] = true;
	
	if (s == t) return minn;
	for(ll i = 1; i < tam; i++){
		if(!visited[i] && graph[s][i] > 0){
			if(ll sent = send(i, t, min(minn, graph[s][i]))){
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
	ll s = 0, t, num, u, v, c, b, d;
	
	while(cin >> n)
	{
		memset(graph, false, sizeof graph);
		
		for(ll i = 1; i <= n; i++)
		{
			cin >> num;
			graph[i][n+i] = num;
		}
		
		cin >> m;
		
		for(ll i = 1; i <= m; i++)
		{
			cin >> u >> v >> c;
			graph[n+u][v] += c;
		}
		
		cin >> b >> d;
		
		tam = 2 + 2*n;
		t = tam-1;
		
		for(ll i = 0 ; i < b; i++)
		{
			cin >> u;
			graph[s][u] = INT_MAX;
		}
		
		for(ll i = 0; i < d; i++)
		{
			cin >> u;
			graph[n+u][t] = INT_MAX;
		}
		
		ll res = 0;
		memset(visited, false, sizeof visited);
		while(ll sent = send(s, t, INT_MAX))
		{
			res += sent;
			memset(visited, false, sizeof visited); 
		}
		
		cout << res << endl;
	}
}
