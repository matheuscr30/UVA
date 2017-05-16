#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

main()
{
	vector<ll>vet;
	ll n, num;
	
	while(cin >> n && n)
	{
		vet.clear();
		for(ll i = 0 ;i  < n; i++){
			cin >> num;
			
			if(num > 0)
				vet.push_back(num);
		}
		
		if(vet.size() == 0)
			cout << 0 << endl;
		else
		{
			for(ll i = 0 ; i < vet.size(); i++)
			{
				if(i != 0)
					cout << " ";
				cout << vet[i];
			}
			cout << endl;
		}
	}
}
