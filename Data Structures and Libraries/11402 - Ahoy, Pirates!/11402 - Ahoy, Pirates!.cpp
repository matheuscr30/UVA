#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n;
vector<ll>lazy, st;
string str;

void reset()
{
  st.clear();
  lazy.clear();
  st.assign(4*n, 0);
  lazy.assign(4*n, 0);
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
  {
    ll c = (ll)str[l] - '0';
    st[p] = c;
    return;
  }
  else
  {
    ll mid = (l+r)/2;
    ll p1 = left(p), p2 = right(p);

    build(p1, l, mid);
    build(p2, mid+1, r);

    st[p] = st[p1] + st[p2];
  }
}

void change(ll p, ll value, ll l, ll r)
{
  if (value == 1){
    st[p] = 0;
  }
  else if (value == 2){
    st[p] = (r-l+1);
  }
  else{
    st[p] = (r-l+1) - st[p];
  }
}

void update(ll p, ll l, ll r, ll a, ll b, ll value)
{
  ll p1 = left(p);
  ll p2 = right(p);

  if (lazy[p] != 0)
  {
    change(p, lazy[p], l, r);
    if (l != r)
    {
      if (lazy[p] == 1 || lazy[p] == 2){
        lazy[p1] = lazy[p];
        lazy[p2] = lazy[p];
      }
      else if (lazy[p] == 3)
      {
        if (lazy[p1] == 0) lazy[p1] = lazy[p];
        else lazy[p1] = (lazy[p1] != 3) ? ((lazy[p1] == 2)? 1:2) : 0;

        if (lazy[p2] == 0) lazy[p2] = lazy[p];
        else lazy[p2] = (lazy[p2] != 3) ? ((lazy[p2] == 2)? 1:2) : 0;
      }
    }
    lazy[p] = 0;
  }

  if (a > r || b < l)
    return;

  if (l >= a && r <= b)
  {
    change(p, value, l, r);

    if (l != r)
    {
      if (value == 1 || value == 2){
        lazy[p1] = value;
        lazy[p2] = value;
      }
      else if (value == 3)
      {
        if (lazy[p1] == 0) lazy[p1] = value;
        else lazy[p1] = (lazy[p1] != 3) ? ((lazy[p1] == 2)? 1:2) : 0;

        if (lazy[p2] == 0) lazy[p2] = value;
        else lazy[p2] = (lazy[p2] != 3) ? ((lazy[p2] == 2)? 1:2) : 0;
      }
    }
    return;
  }

  ll mid = (l+r)/2;
  update(p1, l, mid, a, b, value);
  update(p2, mid+1, r, a, b, value);

  st[p] = st[p1] + st[p2];
}

ll query(ll p, ll l, ll r, ll a, ll b)
{
  ll p1 = left(p);
  ll p2 = right(p);

  if (lazy[p] != 0)
  {
    change(p, lazy[p], l, r);
    if (l != r)
    {
      if (lazy[p] == 1 || lazy[p] == 2){
        lazy[p1] = lazy[p];
        lazy[p2] = lazy[p];
      }
      else if (lazy[p] == 3)
      {
        if (lazy[p1] == 0) lazy[p1] = lazy[p];
        else lazy[p1] = (lazy[p1] != 3) ? ((lazy[p1] == 2)? 1:2) : 0;

        if (lazy[p2] == 0) lazy[p2] = lazy[p];
        else lazy[p2] = (lazy[p2] != 3) ? ((lazy[p2] == 2)? 1:2) : 0;
      }
    }
    lazy[p] = 0;
  }

  if (a > r || b < l)
    return 0;

  if (l >= a && r <= b)
    return st[p];

  ll mid = (l+r)/2;
  ll res1 = query(p1, l, mid, a, b);
  ll res2 = query(p2, mid+1, r, a, b);

  return res1 + res2;
}

main()
{
  char c;
  ll t, m, num, q, a, b, cases=1;
  string aux;
  cin >> t;

  while(t--)
  {
    str.clear();
    cin >> m;
    for (int i = 0 ; i < m; i++)
    {
      cin >> num;
      cin.ignore();
      cin >> aux;

      for (int j = 0; j < num; j++)
        str += aux;
    }
    n = str.size();

    reset();
    build(1, 0, n-1);

    cin >> q;
    int querys = 1;
    cout << "Case " << cases++ << ":\n";
    for (int i = 1; i <= q; i++)
    {
      cin.ignore();
      cin >> c >> a >> b;

      if(c == 'F')
        update(1, 0, n-1, a, b, 2);
      else if (c == 'E')
        update(1, 0, n-1, a, b, 1);
      else if (c == 'I')
        update(1, 0, n-1, a, b, 3);
      else
      {
        ll res = query(1, 0, n-1, a, b);
        cout << 'Q' << querys++ << ": " << res << endl;
      }
    }
  }
}
