#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define vi vector<int>

class SegmentTree {
	private:
		vi st, A;
		int n;
		int left( int p ) { return p << 1; }
		int right( int p ) { return ( p << 1 ) + 1; }

		void build( int p, int L, int R ) {
			if( L == R ) st[p] = A[L]; 
			else {
				build( left(p), L, ( L + R )/2 );
				build( right(p), ( L + R )/2 + 1, R );
				int p1 = st[ left(p) ], p2 = st[ right(p) ];
				st[p] = p1*p2;
			}
		}

		int update( int p, int L, int R, int id, int v ) {
			int i = id, j = id;
			if( i > R || j < L ) return st[p];
			if( L == i && R == j ) {
				A[L] = v;
				return st[p] = A[L];
			}

			int p1, p2;
			p1 = update( left(p), L, ( L + R )/2, id, v );
			p2 = update( right(p), ( L + R )/2 + 1, R, id, v );

			return st[p] = p1*p2;
		}

		int rmq( int p, int L, int R, int i, int j ) {
			if( i > R || j < L ) return INF;
			if( L >= i && R <= j ) return st[p];

			int p1 = rmq( left(p), L, ( L + R )/2, i, j );
			int p2 = rmq( right(p), ( L + R )/2 + 1, R, i, j );
			if( p1 == INF ) return p2;
			if( p2 == INF ) return p1;
			return p1*p2;
		}

	public:
		SegmentTree( const vi &_A ) {
			A = _A; n = (int)A.size();
			st.assign( 4*n, 0 );
			build( 1, 0, n-1 );
		}
		int rmq( int i, int j ) { return rmq( 1, 0, n-1, i, j ); }
		int update( int id, int v ) { return update( 1, 0, n-1, id, v ); }
};

int main() {
	int n, k, x;
	char c;
	vi A;

	while( scanf( "%d%d", &n, &k ) != EOF ) {
		A.clear();
		for( int i=0; i<n; i++ )
			scanf( "%d", &x ), A.push_back( x == 0 ? 0 : ( x > 0 ? 1 : -1 ) );
		SegmentTree st( A );
		for( int i=0; i<k; i++ ) {
			scanf( " %c", &c );
			if( c == 'C' ) {
				int i, v;
				scanf( "%d%d", &i, &v );
				st.update( i-1, v == 0 ? 0 : ( v > 0 ? 1 : -1 ) );

			} else {
				int i, j, stv;
				scanf( "%d%d", &i, &j );
				stv = st.rmq( i-1, j-1 );
				printf( "%s", stv == 0 ? "0" : ( stv > 0 ? "+" : "-" ) );
			}
		}
		printf( "\n" );
	}

	return 0;
}