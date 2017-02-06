#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
vector<string>vet;
unordered_map<string, bool>visited;

ll bfs(string orig, string dest)
{
	string str;
	ll cont;
	visited.clear();
	queue< pair<string, int> >pq;
	pq.push( {orig, 0} );
	
	while(!pq.empty())
	{
		str = pq.front().first;
		cont = pq.front().second;
		pq.pop();
		
		visited[str] = true;
		
		if(str == dest)
			return cont;
		
		for(ll i = 0 ; i < vet.size(); i++)
		{
			if (!visited.count(vet[i]) and vet[i].size() == str.size())
			{
				ll differences = 0;
				for(ll j = 0; j < vet[i].size(); j++)
					if (vet[i][j] != str[j])
						differences++;
						
				if (differences <= 1)
					pq.push( {vet[i], cont+1 } );
			}
		}
	}
	
	return -1;
}

main()
{
	ll t;
	string str, s, d;
	bool flag = false;
	cin >> t;
	
	while(t--)
	{
		if(flag)
			cout << endl;
		vet.clear();
		
		while(cin >> str && str != "*")
			vet.push_back(str);
			
		cin.ignore();
			
		while(getline(cin, str) and str != "")
		{
			stringstream ss(str);
			ss >> s >> d;
				
			ll res = bfs(s, d);
			cout << s << " " << d << " " << res << endl;
		}
		flag = true;
	}
}
