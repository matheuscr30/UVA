#include <bits/stdc++.h>

using namespace std;

main()
{
  vector<int>vet;
  int t, n, num;
  cin >> t;

  while(t--)
  {
    vet.clear();
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    int sum = 0;
    for (int i = 1; i < vet.size(); i++)
    {
      int cont = 0;
      for (int j = 0; j < i; j++)
      {
        if (vet[j] <= vet[i]) cont++;
      }
      sum += cont;
    }

    cout << sum << endl;
  }
}
