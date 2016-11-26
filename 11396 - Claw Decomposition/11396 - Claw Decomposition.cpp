#include <bits/stdc++.h>

using namespace std;
#define mp make_pair

vector<vector<int> >grafo(305);
int v, visitados[305];

bool bfs(int source)
{
    queue<pair<int, int> >q;
    memset(visitados, 0, sizeof visitados);

    visitados[source] = 1;
    q.push(mp(source, 1));

    while(!q.empty())
    {
        int v = q.front().first;
        int color = q.front().second;
        q.pop();

        for (int i = 0; i < grafo[v].size(); i++)
        {
            int nova = (color == 1) ? 2 : 1;

            if (!visitados[grafo[v][i]])
                q.push(mp(grafo[v][i], nova)), visitados[grafo[v][i]] = nova;
            else if( visitados[grafo[v][i]] == color)
                return false;
        }
    }

    return true;
}

main()
{
    int a, b;
    while(cin >> v && v)
    {
        for (int i = 0; i <= v; i++)
            grafo[i].clear();

        while(cin >> a >> b && (a+b))
        {
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        if (bfs(1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
