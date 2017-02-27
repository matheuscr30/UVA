#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll n, degree[105], graph[105][105], dp[105], path[105];
vector<ll> res;

void khan()
{
	priority_queue<ll>pq;
	
	for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            pq.push(-i);
	
	while(!pq.empty())
	{
		ll u = -pq.top();
		pq.pop();
		res.push_back(u);
		
		for(ll i = 1 ; i <= n; i++)
			if(graph[u][i] && --degree[i] == 0)
				pq.push(-i);
	}
}

ll solve(ll current)
{
	if(current == res.size()-1)
		return 0LL;
	
	if(dp[current] != -1)
		return dp[current];
		
	ll ans = 0LL;
	
	for(ll i = current+1; i < res.size(); i++)
	{
		if(graph[res[current]][res[i]]){
			ll h = solve(i)+1;
			if(h > ans)
			{
				ans = h;
				path[current] = i;
			}
			else if(h == ans)
			{	
				ll ends1, ends2;
				
				for(ll j = current; j != -1; j = path[j])
					ends1 = j;
					
				for(ll j = i; j != -1; j = path[j])
					ends2 = j;
				
				if(res[ends2] < res[ends1])
					path[current] = i;
			}
		}
	}
		
	return dp[current] = ans;
}

main()
{
	ll s, p, q, cases=1;
	while(cin >> n && n)
	{
		memset(graph, 0, sizeof graph);
		memset(degree, 0, sizeof degree);
		res.clear();
		
		cin >> s;
		
		while(cin >> p >> q && (p+q))
		{
			graph[p][q] = 1;
			degree[q]++;	
		}
		
		khan();
		
		ll indice;
		for(ll i = 0; i < res.size(); i++){
			if(res[i] == s)
				indice = i;
		}
		
		memset(dp, -1, sizeof dp);
		memset(path, -1, sizeof path);
		ll r = solve(indice);
		
		ll ends;
		for(ll i = indice; i != -1; i = path[i])		
			ends = i;
		
		cout << "Case " << cases++ << ": The longest path from " << s << " has length " << r << ", finishing at " << res[ends] << "." << endl;
		cout << endl;
	}
}
