#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, len;
vector<ll>heights, widths, T, R;

void reset()
{
	heights.clear();
	widths.clear();
}

ll binsearch(ll num)
{
	ll lo = 0;
	ll hi = len;
	
	while(lo <= hi)
	{
		ll mid = (lo+hi)/2;
		
		if (mid < len && heights[T[mid]] < num && num <= heights[T[mid+1]])
			return mid+1;
		else if (heights[T[mid]] < num)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return -1;
}

ll LIS()
{
	T.assign(heights.size(), 0);
	R.assign(heights.size(), -1);
	
	T[0] = 0;
	len = 0;
	
	for (ll i = 1; i < heights.size(); i++)
	{
		if (heights[T[0]] > heights[i]) //Se o valor for menor que o primeiro, substitui 
			T[0] = i;
		else if(heights[T[len]] < heights[i]) //Se o valor for maior que o ultimo substitui
		{
			len++;
			T[len] = i;
			R[T[len]] = T[len-1];
		}
		else
		{
			ll index = binsearch(heights[i]);
			T[index] = i;
			R[T[index]] = T[index-1];
		}
	}
	return len+1;	
}

ll calculate()
{
	ll ans = 0;
	ll index = T[len];
	
	while(index != -1)
	{
		ans += widths[index];
		index = R[index];
	}
	return ans;
}

main()
{                                                                             
	ll t, num, cases=1;
	cin >> t;
	
	while(t--)
	{
		cin >> n;	
		reset();
		
		for (ll i = 0 ; i <  n; i++){
			cin >> num;
			heights.push_back(num);
		}
		
		for (ll i = 0; i < n; i++){
			cin >> num;
			widths.push_back(num);
		}
		
		LIS();
		ll reslis = calculate();
		reverse(heights.begin(), heights.end());
		LIS();
		ll reslds = calculate();
		
		if (reslis >= reslds)
			cout << "Case " << cases++ << ". Increasing (" << reslis << "). Decreasing (" << reslds << ")." << endl;
		else
			cout << "Case " << cases++ << ". Decreasing (" << reslds << "). Increasing (" << reslis << ")." << endl;
	}
}
