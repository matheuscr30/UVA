#include <bits/stdc++.h>

using namespace std;

char v[100][100];
int n1, n2, n3, n4, conta = 0;

void floodFill(int x, int y, char fill, char old)
{
	if(y < 0) y = n2 - 1;
	if(y >= n2) y = 0;
	if (v[x][y] == old)
	{ 
		conta++;
		v[x][y] = fill; 
		floodFill(x+1, y, fill, old);
		floodFill(x, y+1, fill, old); 
		floodFill(x-1, y, fill, old); 
		floodFill(x, y-1, fill, old); 
	} 
}

int main() {
	while(cin >> n1 >> n2 &&n1)
	{
		getchar();
			char c;
			for (int i = 0; i < n1; i++)
			{
				for (int j = 0; j < n2; j++)
				{
					cin >> c;
					v[i][j] = c;
				}			
			}
			cin >> n3 >> n4;
			getchar();
			char p = v[n3][n4];
			floodFill(n3, n4, p+1, p);
			int ans = 0;
			for (int i = 0; i < n1; i++)
			{
				for (int j = 0; j < n2; j++)
				{
					conta = 0;
					if(v[i][j] == p) floodFill(i, j, p+1, p);
					ans = max(ans, conta);
				}
			}
			cout << ans << endl;
		}

return 0;	
}
