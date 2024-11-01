#include <bits/stdc++.h>
using namespace std;
int t, n;
int aans[30] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688};
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1) printf("-1\n");
		else if (n == 2) printf("1\n");
		else if (n == 3) printf("7\n");
		else if (n == 4) printf("4\n");
		else if (n == 5) printf("2\n");
		else if (n == 6) printf("6\n");
		else if (n == 7) printf("8\n");
		else if (n == 8) printf("10\n");
		else if (n == 9) printf("18\n");
		else if (n == 10) printf("22\n");
		else if (n == 11) printf("20\n");
		else if (n == 12) printf("28\n");
		else if (n == 13) printf("68\n");
		else if (n == 14) printf("88\n");
		else if (n == 15) printf("108\n");
		else if (n == 16) printf("188\n");
		else if (n == 17) printf("200\n");
		else if (n == 18) printf("208\n");
		else if (n == 19) printf("288\n");
		else if (n == 20) printf("688\n");
		else if (n % 7 == 0) {
			for (int i = 1; i <= (n / 7); i++) printf("8");
			printf("\n");
		} else if (n % 7 == 1) {
			printf("10");
			for (int i = 1; i < (n / 7); i++) printf("8");
			printf("\n");
		} else {
			printf("%d", aans[n % 7 + 14]);
			for (int i = 1; i <= (n / 7) - 2; i++) printf("8");
			printf("\n");
		}
	}
	return 0;
}