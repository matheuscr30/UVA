#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo(105);
vector<int> res;
vector<int> degree(105);
map<string, int>mapa;
map<int, string>inver;

void khan(int v)
{
    priority_queue<int>p;

    for (int i = 0; i < v; i++)
        if (degree[i] == 0)
            p.push(-i);

    while(!p.empty())
    {
        int u = -p.top();
        p.pop();
        res.push_back(u);

        for (int i = 0; i < grafo[u].size(); i++)
            if (--degree[grafo[u][i]] == 0)
                p.push(-grafo[u][i]);
    }
}

main()
{
    int n, m, casos=1;
    string bebida, b1, b2;

    while(cin >> n)
    {
        cin.ignore();
        mapa.clear();
        inver.clear();
        res.clear();
        int indice = 0;
        for (int i = 0; i < n; i++)
        {
            getline(cin, bebida);
            grafo[i].clear();
            mapa[bebida] = indice;
            inver[indice] = bebida;
            indice++;
        }

        fill(degree.begin(), degree.end(), 0);
        cin >> m;
        while(m--)
        {
            cin.ignore();
            cin >> b1 >> b2;

            grafo[mapa[b1]].push_back(mapa[b2]);
            degree[mapa[b2]]++;
        }

        khan(n);

        cout << "Case #" << casos++ << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < res.size(); i++)
            cout << " " << inver[res[i]];
        cout << "." << endl << endl;
        cin.ignore();
    }
}
