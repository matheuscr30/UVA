#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n;
map<ll, ll>freq, start, fim;
vector<ll> st, vet;

void reset()
{
  start.clear();
  fim.clear();
  freq.clear();
  vet.clear();
  st.clear();
  st.assign(4*n, 0);
}

ll left(ll p){
  return (p << 1);
}

ll right(ll p){
  return (p << 1) + 1;
}

void build(ll p, ll l, ll r)
{
  if (l == r)
    st[p] = freq[vet[l]];
  else
  {
    ll p1 = left(p), p2 = right(p);
    ll mid = (l+r)/2;

    build(p1, l, mid);
    build(p2, mid+1, r);

    st[p] = max(st[p1], st[p2]);
  }
}

ll query(ll p, ll l, ll r, ll a, ll b)
{
  if (a > r || b < l)
    return -1;

  if (l >= a && r <= b)
    return st[p];

  ll p1 = left(p), p2 = right(p);
  ll mid = (l+r)/2;

  ll res1 = query(p1, l, mid, a, b);
  ll res2 = query(p2, mid+1, r, a, b);
  
  return max(res1, res2);
}

main()
{
  ll q, num;

  while(cin >> n && n != 0)
  {
    cin >> q;

    reset();
    for (ll i = 0; i < n; i++)
    {
      cin >> num;
      vet.push_back(num);

      freq[num]++;
      if (freq[num] == 1)
        start[num] = i;
    }

    for (ll i = 0; i < n; i++)
      fim[vet[i]] = start[vet[i]] + freq[vet[i]] -1;

    build(1, 0, n-1);

    ll x, y, ans;
    while(q--)
    {
      cin >> x >> y;
      x--; y--;

      if (vet[x] == vet[y])
        ans = y-x+1;
      else{
        ll v1 = fim[vet[x]] - x + 1;
        ll v2 = y - start[vet[y]] + 1;
        ans = max(v1, v2);

        ll x1 = fim[vet[x]] + 1;
        ll y1 = start[vet[y]] - 1;

        if (y1 >= x1)
        {
          ll v3 = query(1, 0, n-1, x1, y1);
          ans = max(ans, v3);
        }
      }

      cout << ans << endl;
    }

  }
}
