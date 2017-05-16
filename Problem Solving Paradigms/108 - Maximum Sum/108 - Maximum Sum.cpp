#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll mat[105][105], n, maxi, maxStart, maxEnd, maxSum, leftBound, rightBound, upBound, lowBound;
vector<ll>vet;

void kadane()
{
	ll currentStart, maxSoFar;
    
    maxi = currentStart = maxSoFar = 0;
    maxStart = maxEnd = -1;
    
    for(int i=0; i < vet.size(); i++){
        maxSoFar += vet[i];
        if(maxSoFar < 0){
            maxSoFar = 0;
            currentStart = i+1;
        }
        if(maxi < maxSoFar){
            maxStart = currentStart;
            maxEnd = i;
            maxi = maxSoFar;
        }
    }
}

ll solve()
{
	for (ll left = 0; left < n; left++)
	{
		vet.assign(n, 0);
		for (ll right = left; right < n; right++)
		{
			for (ll i = 0 ; i <n; i++)
				vet[i] += mat[i][right];
			
			kadane();
			
			if (maxi > maxSum){
				maxSum = maxi;
				leftBound = left;
				rightBound = right;
				upBound = maxStart;
				lowBound = maxEnd;
			}	
		}
	}
	
	return maxSum;
}

main()
{
	cin >> n;
	
	for(ll i = 0 ; i < n; i++)
		for (ll j = 0; j < n; j++)
			cin >> mat[i][j];
			
	cout << solve() << endl;
}

	
