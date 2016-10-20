#include <bits/stdc++.h>

using namespace std;

bool visitados[105];
vector<vector<int> >grafo(105);
vector<int>vet;

void dfs(int v)
{
    visitados[v] = true;

    for (int i = 0; i < grafo[v].size(); i++)
    {
        if (!visitados[grafo[v][i]])
            dfs(grafo[v][i]);
    }
    vet.push_back(v);
}

int main()
{
    int n, m, i, j;

    while(cin >> n >> m && (n+m))
    {
        vet.clear();
        memset(visitados, false, sizeof visitados);
        for (int i = 0; i <= n; i++)
            grafo[i].clear();

        while(m--)
        {
            cin >> i >> j;
            grafo[i].push_back(j);
        }

        for (int i = 1; i <= n; i++)
            if (!visitados[i])
                dfs(i);

        for (int i = vet.size()-1; i >=0; i--)
            cout << vet[i] << " ";
        cout << endl;
    }

    return 0;
}
