#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int>vet, st;

int left(int p) {return (p << 1);}
int right(int p) {return (p << 1)+1;}

void build(int p, int l, int r)
{
	if (l == r)
		st[p] = vet[l];
	else
	{
		int mid = (l+r)/2;
		int p1 = left(p), p2 = right(p);
		build(p1, l, mid);
		build(p2, mid+1, r);

		st[p] = st[p1] * st[p2];
	}
}

int query(int p, int l, int r, int a, int b)
{
	if (l >= a && r <= b)
		return st[p];
	else if (a > r || b < l)
	 	return 1;
	else
	{
		int p1 = left(p), p2 = right(p);
		int mid = (l+r)/2;
		int res1 = query(p1, l, mid, a, b);
		int res2 = query(p2, mid+1, r, a, b);

		return res1 * res2;
	}
}

void update(int p, int l, int r, int a, int value)
{
	if (a > r || a < l) return;
	else if(l == r and l == a)
	{
		if (value == 0)
			st[p] = 0;
		else if (value > 0)
			st[p] = 1;
		else
			st[p] = -1;
		return;
	}
	else
	{
		int p1 = left(p), p2 = right(p);
		int mid = (l+r)/2;
		update(p1, l, mid, a, value);
		update(p2, mid+1, r, a, value);

		st[p] = st[p1]*st[p2];
	}
}

main()
{
	char c;
	int num, x, y, res;
	string str;
	while(cin >> n >> k)
	{
		vet.clear();
		st.assign(4*n, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> num;
			if (num > 0) num = 1;
			else if (num < 0) num = -1;
			vet.push_back(num);
		}

		build(1, 0, n-1);

		str.clear();
		for (int i = 0; i < k; i++)
		{
			cin.ignore();
			cin >> c >> x >> y;

			if (c == 'C')
			{
				update(1, 0, n-1, x-1, y);
			}
			else
			{
				res = query(1, 0, n-1, x-1, y-1);
				if (res == 0) str += '0';
				else if (res > 0) str += '+';
				else str += '-';
			}
		}

		cout << str << endl;
	}
}
