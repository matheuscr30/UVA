#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll dp[6][30005];
vector<ll>vet;

main()
{
  ll tot;
  vet.push_back(1);
  vet.push_back(5);
  vet.push_back(10);
  vet.push_back(25);
  vet.push_back(50);

  while(cin >> tot)
  {

    for (ll i = 0 ; i <= tot; i++)
      dp[0][i] = 1;

    for (ll i = 1; i < 5; i++){
      dp[i][0] = 1;
      for (ll j = 1 ; j <= tot; j++)
      {
        dp[i][j] = dp[i-1][j];
        if (j >= vet[i])
          dp[i][j] += dp[i][j - vet[i]];
      }
    }

    cout << dp[4][tot] << endl;
  }
}
