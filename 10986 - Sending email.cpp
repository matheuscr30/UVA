#include <bits/stdc++.h>

using namespace std;

bool visitados[20005];
int distancia[20005], n;
vector<vector<pair<int, int> > > grafo(20005);

int dijsktra(int o, int d)
{
    memset(visitados, false, sizeof visitados);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i = 0; i <= n+1; i++)
        distancia[i] = 20000000;

    distancia[o] = 0;

    pq.push({distancia[o], o});

    while(!pq.empty())
    {
        pair<int, int>p = pq.top();
        pq.pop();
        int u = p.second;

        visitados[u] = true;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first;
            int custo = grafo[u][i].second;

            if (!visitados[v])
            {
                if (distancia[v] > (distancia[u] + custo))
                {
                    distancia[v] = distancia[u] + custo;
                    pq.push({distancia[v], v});
                }
            }
        }
    }

    return distancia[d];
}

main()
{
    int p, m, s, t, u, v, w, casos=1;
    cin >> p;

    while(p--)
    {
        cin >> n >> m >> s >> t;

        for (int i = 0; i <= n; i++)
            grafo[i].clear();

        while(m--)
        {
            cin >> u >> v >> w;
            grafo[u].push_back({v, w});
            grafo[v].push_back({u, w});

        }

        cout << "Case #" << casos++ << ": ";
        int res = dijsktra(s, t);
        if (res == 20000000)
            cout << "unreachable" << endl;
        else
            cout << dijsktra(s, t) << endl;
    }
}
