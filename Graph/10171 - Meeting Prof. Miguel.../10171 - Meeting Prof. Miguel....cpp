#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll dist1[30][30], dist2[30][30];
vector< char >vet;
main()
{
	// A = 0
	ll n, p;
	char age, direction, x, y;
	
	while(cin >> n && n)
	{
		vet.clear();
		for(ll i = 0; i < 30; i++)
				for(ll j = 0; j < 30; j++){
					dist1[i][j] = i == j ? 0 : INT_MAX;
					dist2[i][j] = i == j ? 0 : INT_MAX;
				}
		
		ll best = -1;
		for(ll i = 0 ; i < n; i++)
		{
			cin.ignore();
			cin >> age >> direction >> x >> y >> p;
			ll u = (int)x - 'A', v = (int)y - 'A';
			best = max(best, max(u, v));
			if(u == v) continue;
			
			if (age == 'Y')
			{
				dist1[u][v] = min(dist1[u][v], p);
				
				if(direction == 'B')
					dist1[v][u] = min(dist1[v][u], p);
			}
			else
			{
				dist2[u][v] = min(dist2[u][v], p);
				
				if(direction == 'B')
					dist2[v][u] = min(dist2[v][u], p);
			}
		}
		
		cin.ignore();
		cin >> x >> y;
		ll u = (int)x - 'A', v = (int)y - 'A';
		
		for(ll k = 0; k <= best; k++)
			for(ll i = 0 ; i <=best; i++)
				for(ll j = 0; j <=best; j++)
				{
					dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
					dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
					
				}
		
		ll bx=u, by=v, great = INT_MAX;
		bool flag = false;
		char res;
		for(ll i = 0; i <= 28; i++)
		{
			if(dist1[bx][i] != INT_MAX and dist2[by][i] != INT_MAX)
			{
				flag = true;
				ll value = dist1[bx][i] + dist2[by][i];
				res = i + 'A';
				
				if (value < great)
				{
					vet.clear();
					great = value;
					vet.push_back(res);
				}
				else if(value == great)
					vet.push_back(res);
			}
		}
		sort(vet.begin(), vet.end());
		
		//if (bx == by
		
		if(!flag)
			cout << "You will never meet." << endl;
		else
		{
			cout << great;
			for(ll i = 0; i < vet.size(); i++)
			{
				cout << " " << vet[i];
			}
			cout << endl;
		}
		
	}
}
