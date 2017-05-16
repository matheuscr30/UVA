#include <bits/stdc++.h>
#define EPS 1e-6
#define endl '\n'
using namespace std;
double p, q, r, s, t, u;

double solve(double x){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

main()
{
  //p = r = u = 1;
  //q = s = t = -1;
  //cout << solve(0.500) << endl;
  //cout << solve(0.600) << endl;
  //cout << EPS << endl;
  while(cin >> p >> q >> r >> s >> t >> u)
  {
    double lo = 0.0, hi = 1.0, mid;
    double ans = -1;

    for (int i = 0; i < 100; i++)
    {
      mid = (lo+hi)/2;

      if(solve(mid) > 0.0){
        lo = mid;
      }
      else{
        hi = mid;
      }
    }


    if(fabs(solve(mid)) <= EPS)
      cout << fixed << setprecision(4) << mid << endl;
    else
      cout << "No solution" << endl;
  }
}
