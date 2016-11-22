#include <bits/stdc++.h>

using namespace std;

int parent[200005], total =0;
vector<int>res;
vector< pair<int , pair<int, int> > >grafo, MST;
vector< pair<int , pair<int, int> > >::iterator it;

int findset(int x)
{
    if (x != parent[x])
        parent[x] = findset(parent[x]);

    return parent[x];
}

void UNION(int x, int y)
{
    parent[x] = parent[y];
}

void kruskal()
{
    int pu, pv;

    for (int i = 0; i < grafo.size(); i++)
    {
        pu = findset(grafo[i].second.first);
        pv = findset(grafo[i].second.second);

        if (pu != pv)
        {
            total += grafo[i].first;
            MST.emplace_back(grafo[i]);
            UNION(pu, pv);
        }

        if (pu == pv)
          res.push_back(grafo[i].first);
    }
}
void reset (int n) {
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	total = 0;
    grafo.clear ();
	MST.clear ();
}
int main()
{
    int m, n, x, y, z;

    while (cin >> n >> m && (n+m))
    {
        int tot=0;
        reset(n);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            grafo.push_back( make_pair(z, make_pair(x, y)));
            tot += z;
        }
        sort(grafo.begin(), grafo.end());
        kruskal();

        if (res.size() == 0)
          cout << "forest" << endl;
        else
        {
          for (int i = 0; i < res.size(); i++)
          {
            if (i != 0) cout << " ";
            cout << res[i];
          }
          cout << endl;
        }
        res.clear();
    }
    return 0;
}
