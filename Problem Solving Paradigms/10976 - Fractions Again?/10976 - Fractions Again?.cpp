#include <bits/stdc++.h>

using namespace std;

main()
{
  int k, x, y;

  while(cin >> k)
  {
    int cont = 0;
    for (int x = k + 1; x <= 2*k; x++)
    {
      y = (k * x) % (x - k);

      if (y == 0)
        cont++;
    }
    cout << cont << endl;

    for (int x = k + 1; x <= 2*k; x++)
    {
      int ya = (k*x)/(x-k);
      y = (k * x) % (x - k);

      if (y == 0)
        cout << "1/" << k << " = 1/" << ya << " + 1/" << x << endl;
    }
  }
}
