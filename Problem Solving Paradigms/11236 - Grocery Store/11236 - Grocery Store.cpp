#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

main()
{
  for (ll i = 1; i <= 2000; i++)
  {
    if (pow(i, 4) > 2*10e9) break;
    for (ll j = i; j <= 2000; j++)
    {
      if (i*pow(j, 3) > 2*10e9) break;
      for (ll k = j; k <= 2000; k++)
      {
        if (i*j*pow(k, 2) > 2*10e9) break;
        ll p = (i * j * k);
        ll s = (i + j + k);

        if (p <= 1000000) continue;

        ll a = (1000000 * s) / (p - 1000000);

        if (a < k || s + a > 2000) continue;

        if ((s+a)*1000000 == (p*a))
          cout << fixed << setprecision(2) << i/100.0 << " " << j/100.0 << " " << k/100.0 << " " << a/100.0 << endl;
      }
    }
  }

}
