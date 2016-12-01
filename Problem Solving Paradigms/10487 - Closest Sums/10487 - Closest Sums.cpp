#include <bits/stdc++.h>

using namespace std;

main()
{
  vector<int>vet;
  int n, m, cases=1,num;

  while(cin >> n && n != 0)
  {
    vet.clear();
    for (int i = 0; i < n; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    cin >> m;

    cout << "Case " << cases++ << ":" << endl;
    while(m--)
    {
      int menor = INT_MAX, res;
      cin >> num;

      for (int i = 0; i < vet.size(); i++)
      {
        for(int j = i+1; j < vet.size(); j++)
        {
          int sum = vet[i] + vet[j];

          if (abs(sum-num) < menor)
            menor = abs(sum-num), res = sum;
        }
      }

      cout << "Closest sum to " << num << " is " << res << ".\n";
    }
  }
}
