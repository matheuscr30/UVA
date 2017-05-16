#include <bits/stdc++.h>

using namespace std;
vector<int>parent, r;

int findSet(int i){
  return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
}

bool isSameSet(int i, int j)
{
  return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
  if(!isSameSet(i, j))
  {
    int x = findSet(i);
    int y = findSet(j);

    if (r[x] > r[y]) parent[y] = x;
    else
    {
      parent[x] = y;
      if (r[x] == r[y]) r[y]++;
    }
  }
}

main()
{
  bool flag = true;
  stringstream ss;
  int t, n, a, b, ac, wa;

  cin >> t;
  cin.ignore();

  while(t--)
  {
    if (!flag) cout << endl;
    else cin.ignore();

    ac = wa = 0;
    cin >> n;
    cin.ignore();
    parent.clear();
    r.clear();
    parent.push_back(0);
    r.push_back(0);
    for (int i = 1; i <= n; i++)
      parent.push_back(i), r.push_back(0);

    string str;
    char c;
    while(getline(cin, str) && str != "")
    {
      ss.clear();
      ss << str;
      ss >> str;
      c = str[0];
      ss >> a;
      ss >> b;

      //cout << c << a << b << endl;

      if (c == 'c')
      {
        unionSet(a, b);
      }
      else{
        if (isSameSet(a, b))
          ac++;
        else
          wa++;
      }
    }

    cout << ac << "," << wa << endl;
    flag = false;
  }

}
