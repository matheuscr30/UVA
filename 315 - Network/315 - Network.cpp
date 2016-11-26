#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >grafo(105);
int n, root, rootChildren, counter, criticos;
vector<int> dfs_low, dfs_num, dfs_parent;
bool articulationVertex[105];

void points(int u)
{
    dfs_low[u] = dfs_num[u] = counter++;

    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];

        if (dfs_num[v] == -1)
        {
            dfs_parent[v] = u;
            if (u == root) rootChildren++;

            points(v);

            if (dfs_low[v] >= dfs_num[u])
                articulationVertex[u] = true;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void reset(int v)
{
    criticos = 0;
    counter = 0;
    dfs_num.assign(v+1, -1);
    dfs_low.assign(v+1, 0);
    dfs_parent.assign(v+1, 0);
    memset(articulationVertex, false, sizeof articulationVertex);
}

main()
{
    stringstream ss;
    string str;
    while(cin >> n && n)
    {
        for (int i = 0; i <= n; i++)
            grafo[i].clear();

        cin.ignore();

        while(getline(cin, str) && str != "0")
        {
            int vertice, num;
            ss.clear();
            ss << str;
            ss >> vertice;

            while(ss >> num)
            {
                grafo[vertice].push_back(num);
                grafo[num].push_back(vertice);
            }
        }

        reset(n);

        for (int i = 1; i <= n; i++)
        {
            if (dfs_num[i] == -1){
                root = i;
                rootChildren = 0;
                points(i);
                articulationVertex[i] = (rootChildren > 1);
            }
        }

        for (int i = 1; i <= n; i++)
            if (articulationVertex[i])
                criticos++;
        cout << criticos << endl;
    }
}
