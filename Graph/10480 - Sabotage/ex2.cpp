#include <bits/stdc++.h>
using namespace std ;

#define MAXV 55
int res [MAXV][MAXV] ;
int cap [MAXV][MAXV] ;
int s , y , mf ,t , f , N , M ;
bool visited [MAXV] ;
vector <int> p ;

void augment ( int v ,int minedge){ if( p[v] == -1){ f=  minedge;  return ;}
      else{ augment(p[v] , min(minedge,res[p[v]][v]) );
          res[p[v]][v] -= f;
          res[v][p[v]] += f;
          
       }
}

void maxflow(){
 f =mf = 0 ;
 while(1){
  p.assign(N+1,-1);
  bitset<MAXV> vis ; queue<int> q ; vis.set(s); q.push(s);
  while(!q.empty()){ int u = q.front(); q.pop(); if( u == t)break;
               for( int i = 1 ; i<= N ; i++)
               if( !vis.test(i) && res[u][i] > 0){
                 q.push(i) ; vis.set(i); p[i]=u;
               }
  }
  
  augment(t,1e9 );
  if( f== 0 || f == 1e9){ break ;}
  mf += f;
 }
}

void dfs( int u){
 visited[u] = true ;
 for( int i = 1 ; i <= N ; i++)
 if( res[u][i] > 0 && !visited[i])
    dfs(i) ;
}

int main(){
 int i , j, k , l;
 while ( scanf("%d %d",&N ,&M) ){
  if( N == 0 && M == 0)
  break;
         memset ( cap, 0, sizeof cap) ; memset ( res , 0 ,sizeof res);
         while( M--){
          scanf("%d %d %d",&i,&j,&k);
          res[i][j] = res[j][i] = k;
          cap[i][j] = cap[j][i] = k ;
         }
        s = 1 ; t = 2 ;
        maxflow();
        memset ( visited, false,sizeof visited); 
        dfs(s);
        cout << mf << endl;
        for (  i = 1 ; i <= N && mf ; i++)
        for ( j = 1 ; j <= N && mf; j++)
        if( visited[i] && !visited[j] && cap[i][j] > 0 ){
         printf("%d %d\n",i , j) ; mf -= cap[i][j] ;
        }
       putchar('\n');
  }    

  return 0 ;
}
