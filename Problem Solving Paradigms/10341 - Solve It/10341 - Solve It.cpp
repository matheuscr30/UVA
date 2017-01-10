#include <bits/stdc++.h>
#define EPS 1e-5
using namespace std;
typedef long long int ll;
double p, q, r, s, t, u;

bool solve(double x)
{
  double conta = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
  cout << conta << endl;
  return (fabs(conta) >=  EPS) ? true : false;
}

main()
{
  while(cin >> p >> q >> r >> s >> t >> u)
  {
    double ans = -1;
    //0cout << solve(0.7554) << endl;
    double hi = 1.0000, lo = 0.0000, mid;
    while(fabs(hi - lo) > EPS)
    {
      mid = (lo + hi )/2.0;

      if (solve(mid))
      {
        ans = mid;
        hi = mid;
      }
      else lo = mid;
    }

    if (ans == -1)
      cout << "No solution" << endl;
    else
      cout << ans << endl;
  }
}
