#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

main()
{
	vector<int>vet;
	int t, n, num, cases=1;
	cin >> t;
	
	while(t--)
	{
		vet.clear();
		cin >> n;
		
		for(int i = 0 ; i < n; i++)
		{
			cin >> num;
			vet.push_back(num);
		}
		
		int ans = n/2;
		cout << "Case " << cases++ << ": " << vet[ans] << endl;
	}
}
