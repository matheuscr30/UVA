#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
int n;
int grafo[200][200];
bool visitados[200][200];

bool pode(int x, int y){
	return x>=0 && x<n && y>=0 && y<n && !visitados[x][y] && grafo[x][y]!='.';
}

void dfs(int x, int y){
	if(visitados[x][y]) return;
	visitados[x][y]=1;

	for(int i=0; i<4; i++){
		if(pode(x+dx[i], y+dy[i])) dfs(x+dx[i], y+dy[i]);
	}
}

int main() {
    int t;
	cin >> t;
	int caso=1;

	while(t--){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> grafo[i][j];
			}
		}
		memset(visitados, false, sizeof visitados);
		int cont=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(!visitados[i][j] && grafo[i][j]=='x'){
					dfs(i, j);
					cont++;
				}
			}
		}
		printf("Case %d: ", caso++);
		cout << cont << endl;
	}
}
