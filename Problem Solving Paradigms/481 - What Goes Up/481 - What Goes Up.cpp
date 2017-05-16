#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
vector<ll>vet, T, R;
ll len;

ll binsearch(ll num)
{
	ll lo = 0;
	ll hi = len;
	
	while(lo <= hi)
	{
		ll mid = (lo+hi)/2;
		
		if (mid < len && vet[T[mid]] < num && num <= vet[T[mid+1]])
			return mid+1;
		else if (vet[T[mid]] < num)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return -1;
}

ll LIS()
{
	T.assign(vet.size(), 0);
	R.assign(vet.size(), -1);
	
	T[0] = 0;
	len = 0;
	
	for (ll i = 1; i < vet.size(); i++)
	{
		if (vet[T[0]] > vet[i]) //Se o valor for menor que o primeiro, substitui
			T[0] = i;
		else if(vet[T[len]] < vet[i]) //Se o valor for maior que o ultimo, substitui
		{
			len++;
			T[len] = i;
			R[T[len]] = T[len-1];;
		}
		else
		{
			ll index = binsearch(vet[i]);
			T[index] = i;
			R[T[index]] = T[index-1];
		}
	}
	
	return len+1; 		
}

void show()
{
	ll index = T[len];
	vector<ll>aux;
	
	while(index != -1)
	{
		aux.push_back(vet[index]);
		index = R[index];
	}
	
	for (ll i = aux.size()-1; i >= 0; i--)
		cout << aux[i] << endl;
} 

main()
{
	ll num;
	
	while(cin >> num)
		vet.push_back(num);
		
	ll res = LIS();
	cout << res << endl << "-" << endl;
	show();
}
