#include <bits/stdc++.h>
using namespace std;
int dm[]={2,1,-1,-2,-2,-1,2,1};
int dn[]={-1,-2,-2,-1,1,2,1,2};
bool visitados[9][9];

bool valid(int x, int y)
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return true;
	return false;
}
int floodfill(int x1,int x2, int f1,int f2){
  queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(0,make_pair(x1,x2)));
    while(!q.empty()){
      int cont = q.front().first;
      int x = q.front().second.first;
      int y = q.front().second.second;
      q.pop();
      if(x==f1 && f2==y){
        return cont;
      }
      for(int i=0;i<8;i++){
        if(valid(x+dm[i],y+dn[i]) && !visitados[x+dm[i]][y+dn[i]]){
            q.push(make_pair(cont+1,make_pair(x+dm[i],y+dn[i])));
        }
      }
    }
}

main()
{
  char c1,c2;
  int i,j,from,to;

  while(scanf("%c%d %c%d",&c1,&from,&c2,&to)!=EOF){
    getchar();
    memset(visitados,false,sizeof(visitados));
    cout << "To get from " << c1 << from << " to " << c2 << to << " takes " << floodfill((int)c1-'a',from-1,(int)c2-'a',to-1) << " knight moves." << endl;
  }
}

