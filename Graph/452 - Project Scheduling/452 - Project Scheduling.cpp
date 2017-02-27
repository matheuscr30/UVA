#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll cost[30], graph[30][30], degree[30], dp[30];
vector<ll>vet;

void khan()
{
	priority_queue< ll >pq;
	
	for(ll i = 0; i <= 25; i++)
		if (degree[i] == 0)
			pq.push(-i);
			
	while(!pq.empty())
	{
		ll u = -pq.top();
		pq.pop();
		vet.push_back(u);
		
		for(ll i = 0; i <= 25; i++)
			if(--degree[i] == 0)
				pq.push(-i);
	}
}

void reset()
{
	vet.clear();
	for(ll i = 0; i <= 27; i++)
	{
		cost[i] = degree[i] = 0;
		dp[i] = -1;
		
		for(ll j = 0 ; j <= 27; j++)
			graph[i][j] = 0;
	}
}

ll solve(ll current)
{
	if(dp[current] != -1)
		return dp[current];
		
	ll ans = 0LL;
	
	for(ll i = current+1; i < vet.size(); i++)
	{
		if(!graph[vet[current]][vet[i]]) continue;
		ans = max(ans, solve(i) + graph[vet[current]][vet[i]]);
	}
		
	return dp[current] = ans;
}

main()
{
	string str, aux;
	char letter;
	bool flag = false;
	ll testcases, p;
	cin >> testcases;
	cin.ignore();
	cin.ignore();
	
	while(testcases--)
	{
		if(flag) cout << endl;
		reset();
		while(getline(cin, str) && str != "")
		{
			aux.clear();
			stringstream ss(str);
			ss >> letter;
			ss >> p;
			ss >> aux;
			cost[(ll)letter - 'A'] = p;
			
			for(ll i = 0; i < aux.size(); i++)
			{
				graph[(ll)aux[i] - 'A'][(ll)letter - 'A'] = p;
				degree[(ll)letter - 'A']++;
			} 
		}
	
		khan();
		
		ll res = solve(0);
		cout << res + cost[vet[0]] << endl;
		flag = true;
	}
}
