#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >grafo(30), grafoT(30);
map<string, int> string_num;
map<int, string> num_string;
stack<int>s;
int n, m;
bool visitados[30], flag;

void dfs1(int u)
{
    visitados[u] = true;

    for(int i = 0; i < grafo[u].size(); i++)
    {
        if (!visitados[grafo[u][i]])
            dfs1(grafo[u][i]);
    }

    s.push(u);
}

void dfs2(int u)
{
    if (flag) cout << ", ";
    else flag = true;
    cout << num_string[u];
    visitados[u] = true;

    for (int i = 0; i < grafoT[u].size(); i++)
        if (!visitados[grafoT[u][i]])
            dfs2(grafoT[u][i]);
}

void reset()
{
    for (int i = 0; i <= n; i++)
            grafo[i].clear(), grafoT[i].clear();

    num_string.clear();
    string_num.clear();
}

main()
{
    string a, b;
    int casos=1;
    bool ok = false;
    while(cin >> n >> m && (n+m))
    {
        if (ok) cout << endl;

        int indice = 0;
        reset();
        for (int i = 0; i < m; i++)
        {
            cin.ignore();
            cin >> a >> b;

            if (string_num.count(a) == false)
                string_num[a] = indice, num_string[indice] = a, indice++;

            if (string_num.count(b) == false)
                string_num[b] = indice, num_string[indice] = b, indice++;

            grafo[string_num[a]].push_back(string_num[b]);
            grafoT[string_num[b]].push_back(string_num[a]);
        }

        memset(visitados, false, sizeof visitados);

        for (int i = 0; i < n; i++)
            if (!visitados[i])
                dfs1(i);

        memset(visitados, false, sizeof visitados);
        cout << "Calling circles for data set " << casos++ << ":" << endl;

        while(!s.empty())
        {
            int u = s.top();
            s.pop();

            if (!visitados[u])
            {
                flag = false;
                dfs2(u);
                cout << endl;
            }
        }

        ok = true;
    }
}
