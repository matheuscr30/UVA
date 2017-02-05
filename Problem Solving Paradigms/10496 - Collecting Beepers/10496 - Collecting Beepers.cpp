#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
int n, m, dp[405][(1 << 11)], q;
vector< pair<int, int> >v;

int dist(int p1, int p2){
	return abs(v[p1].F - v[p2].F) + abs(v[p1].S - v[p2].S);
}

int solve(int current, int mask)
{
	//cout << current << " " << mask << endl;
	if (mask == (1 << q)-1)
		return dist(current, 0);
	
	if (dp[current][mask] != -1)
		return dp[current][mask];
	
	int ans = INT_MAX;
	mask |= (1 << current);
	
	for(int i = 0; i < q; i++)
	{
		if (!(mask & (1 << i)))
		{
			ans = min(ans, ans+v[current].S);
			ans = min(ans, solve(i, mask | (1 << i)) + dist(current, i));
		}
	}
	
	return dp[current][mask] = ans;
}

main()
{
	int t, start, end, num, x, y;
	cin >> t;
	
	while(t--)
	{
		v.clear();
		cin >> n >> m;
		cin >> start >> end;
		v.push_back( {start, end} );
		
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			cin >> x >> y;
			v.push_back( {x, y} );
		}
		q = v.size();
		
		for (int i = 0 ; i <= q; i++)
			for (int j = 0; j <= (1 << q+1); j++)
				dp[i][j] = -1;
				
		int res = solve(0, 0);
		cout << "The shortest path has length " << res << endl;
	}
}
