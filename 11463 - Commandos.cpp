#include <bits/stdc++.h>
#define INF 1e9

using namespace std;
int dist[200][200];

main()
{
	int t, te = 1, n1, n2, x, y, p, d;
	cin >> t;
	while(t--)
	{
		int ans = 0;
		printf("Case %d: ", te++);
		scanf("%d %d", &n1, &n2);
		for (int i = 0; i <= n1 ; i++)
		{
			for (int j = 0; j <= n1; j++)
				dist[i][j] = INF;
			dist[i][i] = 0;

		}

		for (int i = 0; i < n2; i++)
		{
			scanf("%d %d", &x, &y);
			dist[x][y] = 1;
			dist[y][x] = 1;
		}
		scanf("%d %d", &p, &d);
		for (int k = 0; k < n1; k++)
			for (int i = 0; i < n1; i++)
				for (int j = 0; j < n1; j++)
					dist[i][j] = min(dist[i][j], dist[i][k]  + dist[k][j]);
		for (int i = 0; i < n1; i++)
		{
			if(dist[p][i] + dist[i][d] > ans)
			ans = dist[p][i] + dist[i][d];
		}
		printf("%d\n", ans);

	}

}
