#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
map<string, ll>mapa;
ll dist[105][105];

main()
{
	string s1, s2;
	ll p, r, cases=1;
	
	while(cin >> p >> r && (p+r))
	{
		mapa.clear();
		
		for(ll i = 0 ; i < p; i++)	
			for(ll j = 0 ; j < p ; j++)
				dist[i][j] = i == j ? 0 : INT_MAX;
		
		ll indice = 0;
		cin.ignore();
		for(ll i = 0; i < r; i++)
		{
			cin >> s1 >> s2;
			
			if(!mapa.count(s1))
				mapa[s1] = indice++;
				
			if(!mapa.count(s2))
				mapa[s2] = indice++;
				
			dist[mapa[s1]][mapa[s2]] = 1;
			dist[mapa[s2]][mapa[s1]] = 1;
		}
		
		for(ll k = 0; k < p; k++)
			for(ll i = 0; i < p ; i++)
				for(ll j = 0 ; j < p; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				
		bool flag = true;
		ll maximum =-1;	
		for(ll i = 0; i < p && flag; i++)
		{
			for(ll j = 0; j < p && flag; j++)
			{
				if(dist[i][j] == INT_MAX)
					flag = false;
					
				maximum = max(maximum, dist[i][j]);
			}
		}
		
		if(flag)
			cout << "Network " << cases++ << ": " << maximum << endl << endl;
		else
			cout << "Network " << cases++ << ": " << "DISCONNECTED" << endl << endl;
	}	
}

