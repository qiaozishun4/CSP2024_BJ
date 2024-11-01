#include <iostream>
#include <cstdio>
using namespace std;

int T;
int need[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans = 2e9;

void dfs(int n, int now) {
	if (now > ans) {
		return ;
	}
	if (n == 0) {
		if (now != 0) {
			ans = min(ans, now);
		} 
		return ;
	}
	if (n < 0) {
		return ;
	}
	for (int i = 0; i < 10; i++) {
		if (now == 0 && i == 0) {
			continue ;
			// 1st cant be 0
		}
		dfs(n - need[i], now * 10 + i);
	}
}

void print(int x) {
	for (int i = 1; i <= x; i++) {
		printf("8");
	}
	printf("\n");
} 

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n < 21) {
			dfs(n, 0);
			cout << (ans == 2e9 ? -1 : ans) << endl;
			ans = 2e9;
		} else {
			switch (n % 7) {
				case 0: 
					print(n / 7);
					break ;
				case 1:
					printf("10");
					print(n / 7 - 1);
					break ;
				case 2:
					printf("1");
					print(n / 7);
					break ;
				case 3:
					printf("200");
					print(n / 7 - 2);
					break ;
				case 4:
					printf("20");
					print(n / 7 - 1);
					break ;
				case 5:
					printf("2");
					print(n / 7);
					break ;
				case 6:
					printf("6");
					print(n / 7);
					break ;
			}
		}
	}
	return 0;
}