#include <bits/stdc++.h>

using namespace std;

main()
{
  int n, a, b, c;
  cin >> n;

  while(n--)
  {
    cin >> a >> b >> c;

    bool flag = false;
    for (int x = -100; x <= 100 && !flag; x++)
    {
      for (int y = -100; y <= 100 && !flag; y++)
      {
        for (int z = -100; z <= 100 && !flag; z++)
        {
          if (x != y && y != z && x != z && x*y*z == b && x+y+z == a && x*x+y*y+z*z == c)
            flag = true, cout << x << " " << y << " " << z << endl;
        }
      }
    }

    if (!flag) cout << "No solution." << endl;
  }
}
