#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

void readline (char *s) {
	int n = 0; char c;
	while ((c = getchar ()) != '\n' && c != EOF) {
		s[n ++] = c;
	}
	s[n] = '\0';
	return ;
}

int n;
bool f[10][30];
char s[10];

int main () {
	freopen("poker.in", "r", stdin);
	freopen("poker.ans", "w", stdout);
	scanf("%d", &n);
	while (n --) {
		scanf("%s", s + 1);
		int t;
		if (s[1] == 'D') {
			s[1] = '1';
		} else if (s[1] == 'C') {
			s[1] = '2';
		} else if (s[1] == 'H') {
			s[1] = '3';
		} else if (s[1] == 'S') {
			s[1] = '4';
		} if (s[2] == 'T') {
			t = 10;
		} else if (s[2] == 'J') {
			t = 11;
		} else if (s[2] == 'Q') {
			t = 12;
		} else if (s[2] == 'K') {
			t = 13;
		} else if (s[2] == 'A') {
			t = 1;
		} else {
			t = s[2] - '0';
		}
		f[s[1] - '0'][t] = true;
	}
	int ans = 0;
	for (int i = 1; i <= 4; i ++) {
		for (int j = 1; j <= 13; j ++) {
			if (f[i][j] == false) {
				ans ++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}