#include <bits/stdc++.h>
#define endl '\n'
#define INF 2000000
using namespace std;
typedef long long int ll;
vector<ll>vet, v2;
ll n, q, nt, dist[55][55], tot_cost, dp[15][(1 << 15)];

ll solve(ll pos, ll mask)
{
	if (mask == (1 << nt)-1)
		return dist[vet[pos]][0];

	if (dp[pos][mask] != -1)
		return dp[pos][mask];

	ll ans = INF;
	mask |= (1LL << pos);

	for (ll i = 1; i <= q; i++)
	{
		if (!(mask & (1LL << i)) and dist[vet[pos]][vet[i]] != INF)
		{
			//cout << vet[pos] << " " << vet[i] << " " << dist[vet[pos]][vet[i]] << endl;
			ans = min(ans, dist[vet[pos]][vet[i]] + solve(i, mask | (1LL << i)));
			ans = min(ans, v2[i] + solve(pos, mask | (1LL << i)));
			//cout << 'v' << " " << ans << endl;
		}
	}

	return dp[pos][mask] = ans;
}

void reset()
{
	v2.clear();
	vet.clear();
	vet.push_back(0);
	v2.push_back(0);
}

main()
{
	ll t, m, u, v, p1, p2, p;
	cin >> t;

	while(t--)
	{
		cin.ignore();
		cin.ignore();
		reset();
		cin >> n >> m;

		for(ll i = 0; i <= n; i++)
			for(ll j = 0; j <= n; j++)
				dist[i][j] = (i == j ? 0 : INF);

		for(ll i = 0 ;i < m; i++){
			scanf("%lld %lld %lld.%lld", &u, &v, &p1, &p2);
			p = p1*100 + p2;
			dist[u][v] = min(dist[u][v], p);
			dist[v][u] = min(dist[v][u], p);
		}

		cin >> q;
		tot_cost = 0;
		
		for(ll i = 0; i < q; i++){
			scanf("%lld %lld.%lld", &u, &p1, &p2);
			p = p1*100 + p2;
			tot_cost += p;
			vet.push_back(u);
			v2.push_back(p);
		}
		nt = q+1;

		for (ll k = 0; k <= n; k++)
			for (ll i = 0; i <= n; i++)
				for (ll j = 0; j <= n; j++)
					dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);

		memset(dp, -1, sizeof dp);
		ll res = solve(0, 0);

		if(tot_cost - res > 0)
		{
			double ok = (double)(tot_cost - res)/100.0;
			cout << "Daniel can save $" << fixed << setprecision(2) << ok << endl;
		}
		else
			cout << "Don't leave the house" << endl;
	}
}
