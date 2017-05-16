#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

main()
{
	int vet[12];
	string str;
	int t, n;
	cin >> t;
	
	while(t--)
	{
		memset(vet, 0, sizeof vet);
		cin >> n;
		
		for(int i = 1; i <= n; i++)
		{
			int aux = i;
			while(aux != 0)
			{
				int resto = aux%10;
				vet[resto]++;
				aux /= 10;
			}
		}
		
		for(int i = 0; i < 10; i++)
		{
			if(i)
				cout << " ";
			cout << vet[i];
		}
		cout << endl;
	}
}
