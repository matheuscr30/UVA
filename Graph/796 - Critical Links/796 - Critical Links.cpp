#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> >vet;
vector<vector<int> >grafo(1005);
vector<int> dfs_num, dfs_low, dfs_parent;
int counter, root, rootChildren, n;

void dfs(int u)
{
    dfs_low[u] = dfs_num[u] = counter++;

    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];

        if (dfs_num[v] == -1)
        {
            dfs_parent[v] = u;
            if (u == root) rootChildren++;

            dfs(v);

            if (dfs_low[v] > dfs_num[u])
            {
                int a = u, a1 = v;
                if (a > a1) swap(a, a1);

                vet.push_back({a, a1});
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void reset(int v)
{
    vet.clear();
    counter = 0;
    dfs_num.assign(v+1, -1);
    dfs_low.assign(v+1, 0);
    dfs_parent.assign(v+1, 0);
}

main()
{
    int vertice, num;
    string str;
    stringstream ss;
    while(cin >> n)
    {
        for(int i = 0; i <= n; i++)
            grafo[i].clear();

        for(int i = 0; i < n; i++)
        {
            ss.clear();
            cin >> vertice >> str;
            cin.ignore();
            if (str[1] == '0') continue;
            getline(cin, str);
            ss << str;

            while(ss >> num)
            {
                grafo[vertice].push_back(num);
                grafo[num].push_back(vertice);
            }
        }
        cin.ignore();

        reset(n);

        for (int i = 0; i < n; i++)
        {
            if (dfs_num[i] == -1)
            {
                root = i;
                rootChildren = 0;
                dfs(i);
            }
        }

        cout << vet.size() << " critical links" << endl;
        sort(vet.begin(), vet.end());

        for (int i = 0; i < vet.size(); i++)
        {
            cout << vet[i].first << " - " << vet[i].second << endl;
        }
        cout << endl;
    }
}
