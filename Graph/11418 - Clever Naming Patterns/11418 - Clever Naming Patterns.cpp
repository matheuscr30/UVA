#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll tam, graph[500][500];
bool visited[500];
unordered_map<string, ll>mapa;

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
	string str;
	ll testcases, cases=1, n, s=0, t, num;
	cin >> testcases;
	
	while(testcases--)
	{
		mapa.clear();
		memset(graph, 0, sizeof graph);
		cin >> n;
		ll indice = n+1;
		
		for(ll i = 1; i <= n; i++)
		{
			cin >> num;
			graph[s][i] = 1;
			
			for(ll j = 1; j <= num; j++)
			{
				cin >> str;
				str[0] = toupper(str[0]);
				ll eoq = (ll)str[0] -'A';
				if(eoq > n) continue;
				
				for(ll i = 1; i < str.size(); i++)
					str[i] = tolower(str[i]);
				
				if(!mapa.count(str)){
					mapa[str] = indice;
					indice++;
				}
					
				graph[i][mapa[str]] = 1;
			}
		}
		
		t = tam = indice + n;
		for(ll i = indice; i < indice+n; i++)
			graph[i][t] = 1;
		
		for (unordered_map<string, ll>::iterator it = mapa.begin(); it != mapa.end(); it++)
		{
			string s1 = it->first;
			char c = s1[0];
			num = (ll)c - 'A';
			graph[it->second][indice+num] = 1;
		}
		
		memset(visited, false, sizeof visited);
		ll res = 0;
		while(ll sent = send(s, t, INT_MAX))
		{
			res += sent;
			memset(visited, false, sizeof visited);
		}
		
		cout << "Case #" << cases++ << ":" << endl;
		for(ll i = indice; i < indice+n; i++)
		{	
			for (unordered_map<string, ll>::iterator it = mapa.begin(); it != mapa.end(); it++)
			{
				string s1 = it->first;
				char c = s1[0];
				num = (ll)c - 'A';
				
				if(indice + num == i and graph[it->second][indice+num] == 0)
					cout << s1 << endl;
			}
		}
	}
}
