#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>vet;
	int k;
	bool flag = false;
	while (cin >> k) {
		if (flag) cout << endl;

		int num;
		for (int i = 0; i < k; i++)
            cin >> num, vet.push_back(num);

		for (int a = 0; a < k - 5; a++)
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", vet[a], vet[b], vet[c], vet[d], vet[e], vet[f]);
        flag = true;
	}

	return 0;
}
