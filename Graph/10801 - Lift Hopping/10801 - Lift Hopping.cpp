#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> ii;

int n, k;
vector<vector<int> >grafo(100), grafoE(100);
int seconds[7];
bool visitados[105][10];

int dijkstra(int o, int d)
{
    memset(visitados, false, sizeof visitados);
    priority_queue< pair<int, ii>, vector< pair<int, ii> >, greater< pair<int, ii > > >pq;

    pq.push(mp(0, mp(0, 0))); // {peso, {elevador, andar}}

    while(!pq.empty())
    {
      int custo = pq.top().first;
	     int elevador = pq.top().second.first;
       int andar = pq.top().second.second;
		pq.pop();

		if (visitados[andar][elevador])
            continue;

    visitados[andar][elevador] = true;

		if (andar == d)
			return custo;

		if (elevador != 0)
		{
        for (int i = 0; i < grafoE[elevador].size(); i++)
			{
				int novo = grafoE[elevador][i];
				int cnovo = custo + abs(andar - novo)*seconds[elevador];
				//cout << "E" << cnovo << " " << elevador << " " << novo << endl;

                if(novo != andar && !visitados[novo][elevador])
                    pq.push(mp(cnovo, mp(elevador, novo)));
			}
		}

    for (int i = 0; i < grafo[andar].size(); i++)
		{
			//cout << "Q" << custo << " " << grafo[andar][i] << " " << andar << endl;

			     if (elevador == 0)
                pq.push(mp(custo, mp(grafo[andar][i], andar)));
            else if (elevador != grafo[andar][i] && !visitados[andar][grafo[andar][i]])
                pq.push(mp(custo+60, mp(grafo[andar][i], andar)));
        }
    }

    return -1;
}

main()
{
	int num;
	string str;
	stringstream ss;
	while(cin >> n >> k)
	{
		for (int i = 0; i < 100; i++)
		{
			grafo[i].clear();
			grafoE[i].clear();
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> num;
			seconds[i] = num;
		}

		cin.ignore();
		for (int i = 1; i <= n; i++)
		{
			getline(cin, str);
			ss.clear();
			ss << str;

			while(ss >> num)
			{
				grafoE[i].push_back(num);
				grafo[num].push_back(i);
			}
		}

		int res = dijkstra(0, k);

    if (res != -1) cout << res << endl;
    else cout << "IMPOSSIBLE" << endl;
	}
}
