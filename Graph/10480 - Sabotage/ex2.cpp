#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
unordered_map<string, ll>has;
vector< pair<ll, ll> >vet;
vector< vector<pair<ll, ll> > >distances(1005);
ll n;
double dp[105][55];

ll reset()
{
	has.clear();
	vet.clear();
	
	for(ll i = 0; i <= n; i++)
		for(ll j = 0 ; j <= 52; j++)
			dp[i][j] = -1;
	
	for(ll i = 0; i <= n; i++)
		distances[i].clear();
	return 0;
}

double dist(ll x1, ll y1, ll x2, ll y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

ll solve(ll current, ll opt)
{	
	if(opt == distances[vet[current].F].size())
		return solve(current+1, 0);
	if(current == vet.size())
		return 0;
	
	double &res = dp[current][opt];
	if(res != -1)
		return res;
		
	double ans = INT_MAX;
	
	for(ll i = 0; i < distances[vet[current].S].size(); i++)
	{
		double d = dist(distances[vet[current].F][opt].F, distances[vet[current].F][opt].S,
						distances[vet[current].S][i].F, distances[vet[current].S][i].S);
						
		ans = min(ans, solve(current+1, 0) + d);
	}
		
	return res = ans;
} 

main()
{
	string s1, s2;
	ll quan, num, indice, x, y;
	while(cin >> n && n)
	{
		indice = reset();
		
		for(ll i = 0; i < n; i++)
		{
			cin.ignore();
			cin >> s1 >> quan;
			
			if(!has.count(s1))
				has[s1] = indice++;
				
			for(ll j = 0 ; j < quan; j++)
			{
				cin >> x >> y;
				distances[has[s1]].push_back( {x, y} );
			}
		}
		
		for(ll i = 0; i < n-1; i++)
		{
			cin.ignore();
			cin >> s1 >> s2;
			vet.push_back( {has[s1], has[s2]} );
		}
		
		double res = solve(0, 0);
		cout << fixed << setprecision(1) << res << endl;
	}
}
