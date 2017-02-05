#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll dist[205][205];
unordered_map<string, ll>HASH;

main()
{
	ll n, r, indice, p, cases=1;
	string s1, s2;
	
	while(cin >> n >> r && (n+r))
	{
		HASH.clear();
		indice = 0;
		
		for(ll i = 0; i <= n; i++)
			for(ll j = 0; j <= n; j++)
				dist[i][j] = i == j ? 0 : -1;	
		
		for(ll i = 0; i < r; i++)
		{
			cin.ignore();
			cin >> s1 >> s2 >> p;
			
			if(!HASH.count(s1))
				HASH[s1] = indice++;
				
			if(!HASH.count(s2))
				HASH[s2] = indice++;
				
			dist[HASH[s1]][HASH[s2]] = p;
			dist[HASH[s2]][HASH[s1]] = dist[HASH[s1]][HASH[s2]];
		}
		
		for(ll k = 0; k < indice; k++)
			for(ll i = 0 ; i < indice; i++)
				for(ll j = 0; j < indice; j++)	
					dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
					
		cin.ignore();
		cin >> s1 >> s2;
		
		cout << "Scenario #" << cases++ << endl;
		cout << dist[HASH[s1]][HASH[s2]] << " tons" << endl;
		cout << endl;
	}
}
