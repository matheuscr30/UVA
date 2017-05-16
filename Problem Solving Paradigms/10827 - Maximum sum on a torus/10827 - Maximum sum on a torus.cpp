#include <bits/stdc++.h>
#define eoq cout << "eoq" << endl
using namespace std;
typedef long long int ll;
ll n, mat[170][170];
ll maxi, maxSum;
vector<ll>vet;

void kadane()
{
	ll maxSoFar;
    maxi = maxSoFar = 0;
    
    for(ll j = 0; j < n; j++){
		maxSoFar = 0;
		for(ll i=j; i < vet.size()-(n-j); i++){
			//cout << i << endl;
			maxSoFar += vet[i];
			if(maxSoFar < 0){
				maxSoFar = 0;
			}
			if(maxi < maxSoFar){
				maxi = maxSoFar;
			}
		}
		//cout << maxi << endl;
	}
}

ll solve()
{
	maxSum = 0;
	for (ll left = 0; left < n; left++)
	{
		vet.assign(2*n, 0);
		for (ll right = left; right < 2*n - (n-left); right++)
		{
			ll aux = right%n;
			for(ll i = 0 ; i < 2*n; i++)
				vet[i] += mat[i][aux];
				
			kadane();
			//cout << left << " " << right << " " << maxi << endl;
			
			if (maxi > maxSum){
				maxSum = maxi;
			}
		}
	}
	return maxSum;
}

main()
{
	ll t;
	bool flag;
	cin >> t;
	
	while(t--)
	{
		ll maximum = INT_MIN;
		flag = false;
		vet.clear();
		cin >> n;
		
		for(ll i = 0 ; i < n; i++)
			for(ll j = 0 ; j < n; j++){
				cin >> mat[i][j];
				maximum = max(maximum, mat[i][j]);
				if (mat[i][j] >= 0)
					flag = true;
				mat[i][j+n] = mat[i+n][j] = mat[i][j];
			}
			
		if (flag)
			cout << solve() << endl;
		else
			cout << maximum << endl;
	}
}
