#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef int ll;
typedef pair<ll, ll> ii;
map< ll, ii >mapa;
map< ll, ii >::iterator it, ant;
vector<ii>positions;
ll n, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
ll distances[110], dp[15][15][110][110];
char graph[15][15];
bool visited[15][15], flag;

inline ll solve(ll x, ll y, ll food, ll quan)
{
	//cout << x << " " << y << " " << food << " " << quan << " " << positions.size() << endl;
	if(food == positions.size())
		return 1LL;
	
	if(quan > distances[food])
		return 0LL
		
	char letra = (char)(food + 'A');
	if(graph[x][y] == letra)
		return dp[x][y][food][quan] = solve(positions[food].F, positions[food].S, food+1, 0);
	
	if(dp[x][y][food][quan] != -1)
		return dp[x][y][food][quan];
	
	ll ans = 0LL;	
	
	for(ll i = 0; i < 4; i++)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		
		if(nx < 0 || nx >= n || ny < 0 || ny >= n || graph[nx][ny] == '#') continue;
		
		if(isalpha(graph[nx][ny]))
		{
			if(positions[food].F == nx && positions[food].S == ny)
				ans += solve(nx, ny, food+1, 0);
				
			if(graph[nx][ny] < graph[positions[food].F][positions[food].S])
				ans += solve(nx, ny, food, quan+1);
		}
		else
			ans += solve(nx, ny, food, quan+1);
	}
	
	return dp[x][y][food][quan] = ans%20437;
}

inline ll bfs(ll x1, ll y1, ll x2, ll y2)
{
	memset(visited, false, sizeof visited);
	queue< pair<ll, ii> >pq;
	pq.push( {0, {x1, y1} });
	
	while(!pq.empty())
	{
		ll x = pq.front().S.F;
		ll y = pq.front().S.S;
		ll w = pq.front().F;
		pq.pop();
		
		if(x == x2 && y == y2)
			return w;
			
		visited[x][y] = true;
		
		for(ll i = 0; i < 4; i++)
		{
			ll nx = x + dx[i];
			ll ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= n || graph[nx][ny] == '#') continue;
			
			if(!visited[nx][ny]){
				if(isalpha(graph[nx][ny]))
				{
					if(graph[nx][ny] <= graph[x2][y2]){
						pq.push( {w+1, {nx, ny} } );
						visited[nx][ny] = true;
						continue;
					}
					else
						continue;
				}
				
				pq.push( { w+1, {nx, ny} } );
				visited[nx][ny] = true;
			}
		}
	}
	
	return -1;
}

inline ll calculate()
{
	ll sum = 0; 
	positions.clear();
	ant = mapa.begin();
	ll indice = 1;
	for(it = mapa.begin(); it != mapa.end(); it++)
	{
		positions.push_back( {it->S.F, it->S.S} );
		if(it != mapa.begin())
		{
			ll res = bfs(ant->S.F, ant->S.S, it->S.F, it->S.S);
			distances[indice++] = res;
			sum += res;
			if(res == -1){
				flag = false;
				break;
			}
		}
		ant = it;
	}
	
	return sum;
}

inline void read()
{
	for(ll i = 0; i < n; i++){
		cin.ignore();
		
		for(ll j = 0; j < n; j++){
			cin >> graph[i][j];
			
			if(isalpha(graph[i][j]))
			{
				ll num = (ll)graph[i][j] - 'A';
				mapa[num] = {i, j};
			}
		}
	}
}

main()
{
	ll s, t, cases=1;
	while(cin >> n && n)
	{
		flag = true;
		mapa.clear();
		
		read();
		ll tot = calculate();
		
		cout << "Case " << cases++ << ": ";
		if(!flag){
			cout << "Impossible" << endl;
			continue;
		}
		
		memset(dp, -1, sizeof dp);				
		ll res = solve(positions[0].F, positions[0].S , 1, 0);
		cout << tot << " " << res << endl;
	}
}
