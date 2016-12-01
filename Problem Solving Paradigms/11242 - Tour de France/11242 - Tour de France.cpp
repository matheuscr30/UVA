#include <bits/stdc++.h>

using namespace std;

main()
{
  vector<double>front, rear;
  vector<double>res;
  int f, r, num;

  while(cin >> f && f != 0)
  {
    front.clear();
    rear.clear();
    res.clear();
    cin >> r;

    for(int i = 0; i < f; i++)
    {
      cin >> num;
      front.push_back(num);
    }

    for (int i = 0; i < r; i++)
    {
      cin >> num;
      rear.push_back(num);
    }

    for (int i = 0; i < rear.size(); i++)
    {
      for (int j = 0; j < front.size(); j++)
      {
        double one = rear[i]/front[j];
        res.push_back(one);
      }
    }

    sort(res.begin(), res.end());

    double maior = 0;
    for (int i = 1; i < res.size(); i++)
    {
      double n = res[i]/res[i-1];
      if (n > maior)
        maior = n;
    }

    cout << fixed << setprecision(2) << maior << endl;
  }
}
