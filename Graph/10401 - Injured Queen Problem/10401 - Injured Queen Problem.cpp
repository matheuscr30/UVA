#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
bool graph[20][20];
ll n, need, dp[20][20];
ll dx[] = {1, -1, 0, 1, -1}, dy[] = {0, 0, 1, 1, 1};

ll solve(ll column, ll row)
{
	if(column >= n) return 0LL; 
	
	if(column == n-1)
		return 1LL;
	
	if(dp[column][row] != -1)
		return dp[column][row];
		
	ll ans = 0LL;
	
	bool flag = false;
	for(ll i = 0; i < n; i++)
	{
		ll dist = abs(row-i) + abs(column - (column-1));
		if(graph[i][column] && dist >= 3){
			ans += solve(column+1, i);
			flag = true;
		}
	}
	
	if(!flag)
	{
		for(ll i = 0; i < n; i++)
			ans += solve(column+1, i);
	}
		
	return dp[column][row] = ans;
}

main()
{
	ll num, cont;
	string str;
	
	while(getline(cin, str))
	{
		cont = 0;
		n = str.size();
		memset(graph, true, sizeof graph);
		
		for(ll i = 0; i < str.size(); i++)
		{
			if(str[i] != '?'){
				cont++;
				if(isalpha(str[i]))
				{
					num = str[i] - 'A' + 10 - 1;
				}
				else if(isdigit(str[i]))
				{
					num = str[i] - '1';
				}
				//cout << num << endl;
				
				//cout << "start" << endl;
				graph[num][i] = false;
				//cout << num << " " << i << endl;
				
				for(ll j = 0; j < n; j++){
					graph[j][i] = false;
					//cout << j << " " << i << endl;
				}
					
				for(ll j = 0; j < 5; j++)
				{
					ll nx = num + dx[j];
					ll ny = i + dy[j];
					
					if(nx < 0 || nx > n || ny < 0 || ny > n) continue;
					graph[nx][ny] = false;
					//cout << nx << " " << ny << endl;
				}
				//cout << "ok" << endl;
			}
		}
		
		need = n;
		memset(dp, -1, sizeof dp);
		ll res = solve(0, 0);
		cout << res << endl;
	}
}
