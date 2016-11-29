#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int n, m, s, ri, rj, qnt;
	char mapa[105][105], c;

	while( cin >> n >> m >> s && n && m && s ) {
		qnt = 0;
		for( int i=0; i<n; i++ )
			for( int j=0; j<m; j++ ) {
				cin >> mapa[i][j];
				if( mapa[i][j] == 'N' || mapa[i][j] == 'S' || mapa[i][j] == 'L' || mapa[i][j] == 'O' )
					ri = i, rj = j;
			}
		for( int i=0; i<s; i++ ) {
			cin >> c;
			if( c == 'D' ) {
				switch( mapa[ri][rj] ) {
					case 'N': mapa[ri][rj] = 'L'; break;
					case 'S': mapa[ri][rj] = 'O'; break;
					case 'L': mapa[ri][rj] = 'S'; break;
					case 'O': mapa[ri][rj] = 'N'; break;
				}
			}
			if( c == 'E' ) {
				switch( mapa[ri][rj] ) {
					case 'N': mapa[ri][rj] = 'O'; break;
					case 'S': mapa[ri][rj] = 'L'; break;
					case 'L': mapa[ri][rj] = 'N'; break;
					case 'O': mapa[ri][rj] = 'S'; break;
				}
			}
			if( c == 'F' ) {
				switch( mapa[ri][rj] ) {
					case 'N':
						if( ri-1 >= 0 && mapa[ri-1][rj] != '#' ) {
							ri--;
							if( mapa[ri][rj] == '*' ) qnt++;
							mapa[ri][rj] = mapa[ri+1][rj];
							mapa[ri+1][rj] = '.';
						}
					break;
					case 'S':
						if( ri+1 < n && mapa[ri+1][rj] != '#' ) {
							ri++;
							if( mapa[ri][rj] == '*' ) qnt++;
							mapa[ri][rj] = mapa[ri-1][rj];
							mapa[ri-1][rj] = '.';
						}
					break;
					case 'L':
						if( rj+1 < m && mapa[ri][rj+1] != '#' ) {
							rj++;
							if( mapa[ri][rj] == '*' ) qnt++;
							mapa[ri][rj] = mapa[ri][rj-1];
							mapa[ri][rj-1] = '.';
						}
					break;
					case 'O':
						if( rj-1 >= 0 && mapa[ri][rj-1] != '#' ) {
							rj--;
							if( mapa[ri][rj] == '*' ) qnt++;
							mapa[ri][rj] = mapa[ri][rj+1];
							mapa[ri][rj+1] = '.';
						}
					break;
				}
			}
		}
		cout << qnt << endl;
	}

	return 0;
}