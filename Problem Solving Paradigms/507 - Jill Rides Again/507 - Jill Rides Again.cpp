#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, cases = 1;
	int n, x;
	
	cin >> t;
    while(t--) {
        cin >> n;
        
        int tmp = 1, st , ed, sum = 0, ans = 0;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &x);
            sum += x;
            if (sum < 0) sum = 0, tmp = i;
            if (sum >= ans) {
            	
                if (sum > ans || (sum == ans && (i - tmp > ed - st))) {
                    st = tmp;
                    ed = i;
                }
                ans = sum;
            }
        }
        if (ans > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", cases++, st, ed);
        else
            printf("Route %d has no nice parts\n", cases++);
    }
    return 0;
}
