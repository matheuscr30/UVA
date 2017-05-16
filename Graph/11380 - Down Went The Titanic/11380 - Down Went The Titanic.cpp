#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll graph[1850][1850];
char sea[35][35];
ll dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, x, y;
bool visited[1850];

ll in(ll i, ll j){
	return i*y + j + 2;
}

ll out(ll i, ll j){
	return x*y + i*y + j + 2;
}

ll send(ll s, ll t, ll minn)
{
	visited[s] = true;
	
	if(s == t) return minn;
	for(ll i = 1; i <= out(x, y); i++){
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
	char c;
	ll p, s = 0, t = 1, indice;
	
	while(cin >> x >> y >> p)
	{
		indice = 2;
		memset(graph, 0, sizeof graph);
		ll maior = max(x, y);
		
		for(ll i = 0 ; i < x; i++){
			cin.ignore();
			for(ll j = 0 ; j < y; j++)
				cin >> sea[i][j];
		}
		
		for(ll i = 0 ; i < x; i++)
		{
			for(ll j = 0 ; j < y; j++)
			{
				for(ll k = 0 ; k < 4; k++)
				{
					ll ni = i+dx[k], nj = j+dy[k];
					
					if(ni < 0 || nj < 0 || ni >= x || nj >= y) continue;
					
					graph[out(i, j)][in(ni, nj)] = INT_MAX;
				}
				
				if(sea[i][j] == '*'){
					graph[s][in(i, j)] = 1;
					graph[in(i, j)][out(i, j)] = 1;
				}
				else if(sea[i][j] == '.'){
					graph[in(i, j)][out(i, j)] = 1;
				}
				else if(sea[i][j] == '@'){
					graph[in(i, j)][out(i, j)] = INT_MAX;
				}
				else if(sea[i][j] == '#'){
					graph[in(i, j)][out(i, j)] = INT_MAX;
					graph[out(i, j)][t] = p;
				}
			}
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
