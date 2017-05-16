#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
ii aux;
vector<vector<ii> >st;
ll mat[510][510], n;

ll left(ll p){
  return (p << 1);
}

ll right(ll p){
  return (p << 1) + 1;
}

void build(ll row, ll p, ll l, ll r)
{
  if(l == r)
  {
    st[row][p].F = st[row][p].S = mat[row][l];
    return;
  }

  ll p1 = left(p), p2 = right(p);
  ll mid = (l+r)/2;

  build(row, p1, l, mid);
  build(row, p2, mid+1, r);

  st[row][p].F = max(st[row][p1].F, st[row][p2].F);
  st[row][p].S = min(st[row][p1].S, st[row][p2].S);
}

void update(ll row, ll p, ll l, ll r, ll a, ll value)
{
  if (a > r || a < l)
    return;

  if (l == r and l == a)
  {
    st[row][p].F = st[row][p].S = value;
    return;
  }

  ll p1 = left(p), p2 = right(p);
  ll mid = (l+r)/2;

  update(row, p1, l, mid, a, value);
  update(row, p2, mid+1, r, a, value);

  st[row][p].F = max(st[row][p1].F, st[row][p2].F);
  st[row][p].S = min(st[row][p1].S, st[row][p2].S);
}

ii query(ll row, ll p, ll l, ll r, ll a, ll b)
{
  if (a > r || b < l)
    return aux;

  if (l >= a and r <= b)
    return st[row][p];

  ll p1 = left(p), p2 = right(p);
  ll mid = (l+r)/2;

  ii res1 = query(row, p1, l, mid, a, b);
  ii res2 = query(row, p2, mid+1, r, a, b);

  ii result;
  result.F = max(res1.F, res2.F);
  result.S = min(res1.S, res2.S);

  return result;
}

main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  aux.F = LLONG_MIN;
  aux.S = LLONG_MAX;

  ll num, q, x1, y1, x2, y2 ,v;
  char c;
  cin >> n;

  st.clear();

  vector< ii >vet(4*n, make_pair(0, 0));

  for (ll i = 0; i <= n; i++)
    st.push_back(vet);

  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < n; j++)
      cin >> mat[i][j];

  for (ll i = 0; i < n; i++)
    build(i, 1, 0, n-1);

  cin >> q;

  while(q--)
  {
    cin.ignore();
    cin >> c;

    if (c == 'q')
    {
      cin >> x1 >> y1 >> x2 >> y2;
      x1--; x2--;

      ll maxi = LLONG_MIN, mini = LLONG_MAX;

      for (ll i = x1; i <= x2; i++)
      {
        ii res = query(i, 1, 0, n-1, y1-1, y2-1);
        maxi = max(maxi, res.F);
        mini = min(mini, res.S);
      }

      cout << maxi << " " << mini << endl;
    }
    else
    {
      cin >> x1 >> y1 >> v;
      update(x1-1, 1, 0, n-1, y1-1, v);
    }
  }
}
