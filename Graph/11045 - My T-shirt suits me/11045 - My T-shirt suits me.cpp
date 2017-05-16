#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll graph[75][75], parent[75];
bool visited[75];
unordered_map<string, ll>mapa;
ll s, t, tam;

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
		
		for(ll v = 1; v <= tam; v++)
		{
			if(!visited[v] && graph[u][v] > 0)
			{
				visited[v] = true;
				parent[v] = u;
				q.push(v);
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

ll send(ll s, ll t, ll minn) {
    visited[s] = true;

    if (s==t) return minn;
    for(ll i=1; i<=tam; i++) {
        if (!visited[i] && graph[s][i] > 0) {
            if (ll sent = send(i, t, min(minn, graph[s][i]))) {
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
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	ll k, n, m;
	string s1, s2;
	cin >> k;
	while(k--)
	{
		memset(graph, 0, sizeof graph);
		cin >> n >> m;
		
		s = 0;
		t = tam = n+m+1;

		ll value = n/6;
		mapa["XXL"] =  1;
		mapa["XL"] = 1 + value;
		mapa["L"] = 1 + value*2;
		mapa["M"] = 1 + value*3;
		mapa["S"] = 1 + value*4;
		mapa["XS"] = 1 + value*5;
		
		for(ll i = 1; i <= n; i++)
			graph[s][i] = 1;
			
		for(ll i = 1 ; i <= m; i++)
		{
			ll user = i + n;
			graph[user][t] = 1;
			cin.ignore();
			cin >> s1 >> s2;
			
			for(ll j = mapa[s1]; j < mapa[s1]+value; j++)
				graph[j][user] = 1; 
			
			for(ll j = mapa[s2]; j < mapa[s2]+value; j++)
				graph[j][user] = 1;
		}
		
		ll res = 0;
		memset(visited, 0, sizeof visited);
		while(ll sent = send(0, t, INT_MAX)) {
            res += sent;
            memset(visited, 0, sizeof(visited));
        }
		
		if(res != m)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
