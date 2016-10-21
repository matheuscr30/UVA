#include <bits/stdc++.h>

using namespace std;

vector<vector<int> >grafo(100005), grafoT(100005);
stack<int>s;
bool visitados[100005];
int n, m;

void dfs(int u, int sit)
{
    visitados[u] = true;

    for (int i = 0; i < grafo[u].size(); i++)
        if (!visitados[grafo[u][i]])
            dfs(grafo[u][i], sit);

    if (sit == 1)
        s.push(u);
}

main()
{
    int t, a, b;
    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            grafo[i].clear();

        while(m--)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
        }

        memset(visitados, false, sizeof visitados);

        for (int i = 1; i <= n; i++)
            if (!visitados[i])
                dfs(i, 1);

        memset(visitados, false, sizeof visitados);
        int cont = 0;

        while(!s.empty())
        {
            int u = s.top();
            s.pop();

            if (!visitados[u])
                cont++, dfs(u, 2);
        }

        cout << cont << endl;
    }
}
