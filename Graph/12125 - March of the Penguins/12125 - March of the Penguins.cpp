#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll cost[105],graph[215][215], n, graph2[215][215];
double xs[105], ys[105];
bool visited[215];

ll send(ll s, ll t, ll minn)
{
	visited[s] = true;
	
	if(s == t) return minn;
	for(ll i = 1; i <= 2*(n+1)+2; i++){
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
	ll testcases, s = 0, t = 1, x, y, c1, c2;
	double d;
	cin >> testcases;
	
	while(testcases--)
	{
		memset(graph, 0, sizeof graph);
		memset(graph2, 0, sizeof graph2);
		cin >> n >> d;
		
		ll penguins = 0;
		for(ll i = 2; i <= n+1; i++)
		{
			cin >> xs[i] >> ys[i] >> c1 >> cost[i];
			penguins += c1;
			graph[s][i] = c1;
			graph[i][i+n] = cost[i];
			
			graph2[s][i] = c1;
			graph2[i][i+n] = cost[i];
		}
		
		for(ll i = 2; i <= n+1; i++)
		{
			for(ll j = 2; j <= n+1; j++)
			{
				if(i == j) continue;
				double dist = sqrt( (xs[i] - xs[j])*(xs[i] - xs[j]) + (ys[i] - ys[j])*(ys[i] - ys[j]) );
				//cout << dist << endl;
				if (dist <= d)
				{
					graph[i+n][j] = INT_MAX;
					graph[j+n][i] = INT_MAX;
					
					graph2[i+n][j] = INT_MAX;
					graph2[j+n][i] = INT_MAX;
				}
			}
		}
		
		vector<ll>vet;
		for(ll i = 2; i <= n+1; i++)
		{
			memset(visited, false, sizeof visited);
			ll res = 0;
			
			for(ll i = 0; i <= 2*(n+1)+2; i++)
				for(ll j = 0; j <= 2*(n+1)+2; j++)
					graph[i][j] = graph2[i][j];
			
			while(ll sent = send(s, i, INT_MAX))
			{
				res += sent;
				memset(visited, false, sizeof visited);
			}
			
			if(res == penguins)
				vet.push_back(i-2);
		}
		
		if(vet.size() == 0)
			cout << -1 << endl;
		else
		{
			for(ll i = 0 ; i < vet.size(); i++)
			{
				if (i != 0) cout << " ";
				cout << vet[i];
			}
			cout << endl;
		}
	}
}
