#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll mat[105][105];
main()
{
	ll m, n;
	
	while(cin >> m >> n && (m+n))
	{
		for(ll i = 0; i < m; i++)
		{
			for(ll j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				mat[i][j] = mat[i][j] == 0 ? 1 : -100;
				
				if(i > 0) mat[i][j] += mat[i-1][j];
				if(j > 0) mat[i][j] += mat[i][j-1];
				if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
			}
		}
		
		//for(ll i = 0; i < m; i++)
		//{
		//	for(ll j = 0; j < n; j++)
		//	{
		//		cout << mat[i][j];
		//	}
		//	cout << endl;
		//}
		
		ll maior = INT_MIN;
		for(ll i = 0; i < m; i++)
			for(ll j = 0; j < n; j++)
				for(ll k = i; k < m; k++)
					for(ll l = j; l < n; l++)
					{
						ll sum = mat[k][l];
						
						if(i > 0) sum -= mat[i-1][l];
						if(j > 0) sum -= mat[k][j-1];
						if(i > 0 && j > 0) sum += mat[i-1][j-1];
						maior = max(maior, sum);
					}
						
		cout << maior << endl;

	}
}
