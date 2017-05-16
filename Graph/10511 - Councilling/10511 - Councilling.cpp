#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
unordered_map<string, ll> names, parties, groups;
unordered_map<string, ll>::iterator it, it2;
ll graph[1500][1500], vertice;
bool visited[1500];

ll send(ll s, ll t, ll mmin)
{
	visited[s] = true;
	
	if(s == t) return mmin;
	for(ll i = 1; i < vertice; i++){
		if(!visited[i] && graph[s][i] > 0){
			if(ll sent = send(i, t, min(mmin, graph[s][i])))
			{
				graph[s][i] -= sent;
				graph[i][s] += sent;
				return sent;
			}
		}
	}
	return 0;
}

main()
{
	stringstream ss;
	bool flag = false;
	string str, name, party, group;
	ll k, s = 0, t = 1;
	cin >> k;
	cin.ignore();
	cin.ignore();
	
	while(k--)
	{
		if(flag)
			cout << endl;
		
		memset(graph, false, sizeof graph);
		vertice = 2;
		names.clear();
		parties.clear();
		groups.clear();
		
		while(getline(cin, str) && str != "" && str != " ")
		{
			ss.clear();
			ss << str;
			ss >> name >> party;
			
			if(!names.count(name))
				names[name] = vertice++;
				
			if(!parties.count(party))
				parties[party] = vertice++;
			
			graph[parties[party]][names[name]] = 1;
			
			while(ss >> group)
			{
				if(!groups.count(group))
					groups[group] = vertice++;
					
				graph[names[name]][groups[group]] = 1;
				graph[groups[group]][t] = 1;
			}
		}
		
		ll aux = (groups.size()-1)/2;
		for(it = parties.begin(); it != parties.end(); it++)
			graph[s][it->second] = aux;
			
		ll res = 0;
		memset(visited, false, sizeof visited);
		while(ll sent = send(s, t, INT_MAX)){
			res += sent;
			memset(visited, false, sizeof visited);
		}
		
		if(res != groups.size())
			cout << "Impossible." << endl;
		else
		{
			for(it = groups.begin(); it != groups.end(); it++)
			{
				for(it2 = names.begin(); it2 != names.end(); it2++)
				{
					if(graph[it->second][it2->second])
					{
						cout << it2->first << " " << it->first << endl;
						break;
					}
				}
			}
		}
		
		flag =true;
	}
}
