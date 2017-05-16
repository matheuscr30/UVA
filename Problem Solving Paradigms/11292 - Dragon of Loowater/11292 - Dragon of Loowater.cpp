#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

main()
{
	vector<ll>knights, heads;
	ll n, m, num;
	
	while(cin >> n >> m && (n+m))
	{
		knights.clear();
		heads.clear();
		
		for(ll i = 0 ; i < n; i++){
			cin >> num;
			heads.push_back(num);
		}
		
		for(ll i = 0 ; i < m; i++){
			cin >> num;
			knights.push_back(num);
		}
		
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());
		
		ll pay = 0, ind = 0;
		bool flag;
		
		for(ll i = 0 ; i < heads.size(); i++)
		{
			flag = false;
			while(1)
			{
				if(ind == knights.size())
				{
					flag = true;
					break;
				}
				
				if(knights[ind] >= heads[i])
				{
					pay += knights[ind];
					ind++;
					break;
				}
				
				ind++;
			}
			
			if (flag == true)
			{
				pay = -1;
				break;
			}
		}
		
		if(pay != -1)
			cout << pay << endl;
		else
			cout << "Loowater is doomed!" << endl;
	}
}
