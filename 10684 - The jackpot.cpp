#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
vector<ll>vet;
ll n, dp[10005][5];

ll solve(ll current, ll inf)
{
    if (current == n || inf == 2)
        return 0LL;

    if (dp[current][inf] != -1)
        return dp[current][inf];

    ll ans;

    if (inf == 0)
        ans = max(solve(current+1, 0), solve(current+1, 1) + vet[current]);
    else if (inf == 1)
        ans = max(solve(current+1, 1) + vet[current], solve(current+1, 2));

    return dp[current][inf] = ans;
}

main()
{
    int num;
    while(cin >> n && n)
    {
        vet.clear();
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            cin >> num;
            vet.push_back(num);
        }

        int res = solve(0, 0);

        if (res <= 0)
            cout << "Losing streak." << endl;
        else
            cout << "The maximum winning streak is " << res <<"." << endl;
    }
}
