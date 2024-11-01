#include<iostream>
#include<cstdio>
using namespace std;
const int biao[15] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
int T, n;
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n < 15) {
			printf("%d\n", biao[n]);
		} else {
			int wei = (n - 15) / 7;
			int lei = (n - 15) % 7;
			if (lei == 0)
				printf("108");
			else if (lei == 1)
				printf("188");
			else if (lei == 2)
				printf("200");
			else if (lei == 3)
				printf("208");
			else if (lei == 4)
				printf("288");
			else if (lei == 5)
				printf("688");
			else if (lei == 6)
				printf("888");
			for (int i = 1; i <= wei; i++)
				printf("8");
			printf("\n");
		}
	}
	return 0;
}