#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >grafo(2005);
bool visitados[2005];

void dfs(int v)
{
    visitados[v] = true;

    for (int i = 0; i < grafo[v].size(); i++)
        if (!visitados[grafo[v][i]])
            dfs(grafo[v][i]);
}

main()
{
    int n, m, u, v, p;

    while(cin >> n >> m && (n+m))
    {
        for (int i = 0; i <= n; i++)
            grafo[i].clear();

        while(m--)
        {
            cin >> u >> v >> p;

            grafo[u].push_back(v);

            if (p == 2)
                grafo[v].push_back(u);
        }

        bool conexo = true;

        for (int i = 1; i <= n && conexo; i++)
        {
            memset(visitados, false, sizeof visitados);
            if (!visitados[i])
                dfs(i);

            for (int i = 1; i <= n; i++)
                if (!visitados[i])
                    conexo = false;
        }

        if (conexo) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
