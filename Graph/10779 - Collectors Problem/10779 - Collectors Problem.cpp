#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll stickets[15][55], graph[75][75], t;
bool visited[75];

ll send(ll s, ll t, ll minn)
{
	visited[s] = true;
	
	if(s == t) return minn;
	for(ll i = 2; i <= t; i++){
		if(!visited[i] and graph[s][i] > 0){
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
	ll testcases, cases=1, n, m, num, po ;
	cin >> testcases;
	
	while(testcases--)
	{
		memset(graph, 0, sizeof graph);
		memset(stickets, 0, sizeof stickets);
		cin >> n >> m;
		t = 2*m + 1;
		
		for(ll i = 1; i <= n; i++){
			cin >> num;
			for(ll j = 1; j <= num; j++){
				cin >> po;
				stickets[i][po]++;
			}
		}
				
		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= m; j++)
			{
				graph[m+j][t] = 1;
				if(i == 1)
					graph[1][m+j] = stickets[i][j];
				else
				{
					if(stickets[i][j] > 0) // Tem sobrando
						graph[i][m+j] = stickets[i][j] - 1;
					else // Falta
						graph[m+j][i] = 1;
				}
			}
		}
		
		memset(visited, false, sizeof visited);
		ll res = 0;
		while(ll sent = send(1, t, INT_MAX))
		{
			res += sent;
			memset(visited, false, sizeof visited);
		}
		
		cout << "Case #" << cases++ << ": " << res << endl;
	}
}
