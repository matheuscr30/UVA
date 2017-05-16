#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

main()
{
	string str;
	ll t, n, cases=1;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		cin.ignore();
		cin >> str;
		
		ll crops = 0, cont=0, tot = 0;
		
		for(ll i = 0; i < str.size(); i++)
		{
			cont++;
			
			if(str[i] == '.')
				crops++;
			
			if (crops == 0 && cont == 1)
				cont--;
				
			if(cont == 3 and crops >= 1)
			{
				tot++;
				cont = 0;
				crops = 0;
			}
		}
		
		if(crops >= 1)
			tot++;
		
		ll tot2 = 0;
		crops = cont = 0;
		for(ll i = str.size()-1; i >= 0; i--)
		{
			cont++;
			if(str[i] == '.')
				crops++;
			
			if (crops == 0 && cont == 1)
				cont--;
			
			if(cont == 3 and crops >= 1)
			{
				tot2++;
				cont = 0;
				crops = 0;
			}
		}
		
		if(crops >= 1)
			tot2++;
			
		tot = min(tot, tot2);
			
		cout << "Case " << cases++ << ": " << tot << endl;
	}
}
