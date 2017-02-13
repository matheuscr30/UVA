#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll graph[40][40], parent[40];
bool visited[40];

bool bfs(ll s, ll t)
{
	memset(visited, false, sizeof visited);
	queue<ll>q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;
	
	while(!q.empty())
	{
		ll u = q.front();
		q.pop();
		
		for(ll v = 1; v <= 37; v++)
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
		//ll p1 = parent[t];
		//cout << parent[p1] + 'A' -1 << " " << p1-27 << endl;
		
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
	string s1, s2;
	ll quan, app, sum = 0;
	
	while(getline(cin, s1))
	{
		memset(graph, 0, sizeof graph);
		sum = 0;
		
		for(ll j = 27; j <= 36; j++)
			graph[j][37] = 1;
		
		do
		{
			app = (ll)s1[0] - 'A' + 1;
			quan = (ll) s1[1] - '0';
			sum += quan;
			graph[0][app] += quan;
		
			for(ll i = 3; i < s1.size()-1; i++)
			{
				ll num = (ll)s1[i] - '0' + 27;
				graph[app][num] = 1;
			}
			
			getline(cin, s1);
		}while(!s1.empty());
		
		ll res = EdmondKarps(0, 37);
		
		if(res != sum)
			cout << "!" << endl;
		else
		{
			for(ll i = 27; i < 37; i++)
			{
				bool flag = false;
				
				for(ll j = 1; j <= 26; j++)
				{
					if (graph[i][j]){
						char c = j + 'A' -1;
						cout << c;
						flag = true;
						break;
					}
					
				}
				
				if(!flag)
					cout << '_';
			}
			cout << endl;
		}
	}
}
