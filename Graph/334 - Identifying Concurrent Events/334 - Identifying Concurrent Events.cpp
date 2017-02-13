#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
bool dist[205][205];
map<string, ll>mapa;
map<ll, string>blala;
vector< pair<string, string> >vet;

main()
{
	ll nc, ne, nm, cases=1;
	string s1, ant;
	
	while(cin >> nc && nc)
	{
		mapa.clear();
		blala.clear();
		vet.clear();
		memset(dist, false, sizeof dist);
		
		ll indice = 0;
		for(ll i = 0 ; i < nc; i++)
		{
			cin >> ne;
			
			for(ll j = 0; j < ne; j++)
			{
				cin >> s1;
				
				if(!mapa.count(s1))
					mapa[s1] = indice, blala[indice]=s1, indice++;
				
				if (j != 0)	
					dist[mapa[ant]][mapa[s1]] = true;
					
				ant = s1;
			}
		}
		
		cin >> nm;
		
		for(ll i = 0; i < nm; i++)
		{
			cin.ignore();
			cin >> ant >> s1;
			dist[mapa[ant]][mapa[s1]] = true;
		}
		
		for(ll k = 0; k < indice; k++)
			for(ll i = 0; i < indice; i++)
				for(ll j = 0 ; j < indice; j++)
					dist[i][j] |= (dist[i][k] & dist[k][j]);
					
		ll cont = 0;
		for(ll i = 0; i < indice; i++)
		{
			for(ll j = i+1; j < indice; j++)
			{
				if(!dist[i][j] and !dist[j][i])
				{
					cont++;
					vet.push_back( {blala[i], blala[j] } );
				}
			}
		}
		
		if(cont == 0)
			cout << "Case " << cases++ << ", " << "no concurrent events." << endl;
		else if (cont >= 2){
			cout << "Case " << cases++ << ", " << cont << " concurrent events:" << endl;
			
			for(ll i = 0 ; i < 2; i++)
			{
				cout << "(" << vet[i].first << "," << vet[i].second << ") ";
			}
				
			cout << endl;
		}
		else
		{
			cout << "Case " << cases++ << ", " << cont << " concurrent events:" << endl;
			cout << "(" << vet[0].first << "," << vet[0].second << ") " << endl;
		}
		
		
		
	}
}
