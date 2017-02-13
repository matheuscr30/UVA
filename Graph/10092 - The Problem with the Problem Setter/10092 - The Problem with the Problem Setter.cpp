#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll graph[1100][1100], parent[1100], tam;
bool visited[1100];

ll send(ll s, ll t, ll minn) {
    visited[s] = true;

    if (s==t) return minn;
    for(ll i=1; i<=tam; i++) {
        if (!visited[i] && graph[s][i] > 0) {
            if (ll sent = send(i, t, min(minn, graph[s][i]))) {
                graph[s][i] -= sent;
                graph[i][s] += sent;
                return sent;
            }
        }
    }
    return 0;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll nk, np, num;
	
	while(cin >> nk >> np && (nk+np))
	{
		ll s = 0, t = np+nk+1, sum = 0;
		tam = np + nk + 1;
		memset(graph, 0, sizeof graph);
		
		for(ll i = 1; i <= nk; i++)
		{
			cin >> num;
			sum += num;
			graph[np+i][t] = num;
		}
		
		for(ll i = 1; i <= np; i++)
		{
			ll n;
			cin >> n;
			graph[0][i] = 1;
			
			while(n--)
			{
				cin >> num;
				graph[i][np+num] = 1;
			}
		}
		
		ll res = 0;
		
		memset(visited, 0, sizeof visited);
		while(ll sent = send(0, t, INT_MAX)) {
            res += sent;
            memset(visited, 0, sizeof(visited));
        }
		
		if (res != sum)
			cout << "0" << endl;
		else
		{
			cout << "1" << endl;
			
			for (ll i = np+1; i < t; i++)
			{
				bool printed = false;
				for (ll j = 1; j <= np; j++)
				{
					if(graph[i][j])
					{
						if(printed)
							cout << " ";
						cout << j;
						printed = true;
					}
				}
				cout << endl;
			}
		}
	}
}
