#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

main()
{
	ll n;
	
	cout << "PERFECTION OUTPUT" << endl;
	while(cin >> n && n)
	{
		ll sum = 0;
		for(ll i = 1; i < n; i++)
		{
			if(n%i == 0)
				sum += i;
		}
		
		if(sum == n)
			cout << setw(5) << n << "  PERFECT" << endl;
		else if(sum < n)
			cout << setw(5) << n << "  DEFICIENT" << endl;
		else
			cout << setw(5) << n << "  ABUNDANT" << endl;
	}
	cout << "END OF OUTPUT" << endl;
}
