#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> >grafo(205);
int visitados[205];

bool bfs(int source)
{
    queue< pair<int, int> >q;
    memset(visitados, 0, sizeof visitados);

    visitados[source] = 1;
    q.push({source, 1});

    while(!q.empty())
    {
        int v = q.front().first;
        int color = q.front().second;
        q.pop();

        for (int i = 0; i < grafo[v].size(); i++)
        {
            if (!visitados[grafo[v][i]])
                q.push({grafo[v][i], (color == 1) ? 2 : 1}), visitados[grafo[v][i]] = (color == 1) ? 2 : 1;
            else if (visitados[grafo[v][i]] == color)
                return false;
        }
    }

    return true;
}

main()
{
    int m, a, b;

    while(cin >> n && n != 0)
    {
        cin >> m;
        for (int i = 0; i <= n; i++)
            grafo[i].clear();

        while(m--)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        bool flag = bfs(0);

        if (!flag) cout << "NOT ";
        cout << "BICOLORABLE." << endl;
    }
}
