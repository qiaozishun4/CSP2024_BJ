#include<iostream>
#include<cstdio>
using namespace std;

bool cnt[5][14];
char s[3];
int n;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
	cin >> n;
	int ind;
	for (int i = 1;i <= n;i++) {
		cin >> s;
		ind = (s[0] == 'D' ? 1 : (s[0] == 'C' ? 2 : (s[0] == 'H' ? 3 : 4)));
		if (s[1] >= '2' && s[1] <= '9')
			cnt[ind][s[1] - '0'] = true;
		else if (s[1] == 'A')
			cnt[ind][1] = true;
		else if (s[1] == 'T')
			cnt[ind][10] = true;
		else if (s[1] == 'J')
			cnt[ind][11] = true;
		else if (s[1] == 'Q')
			cnt[ind][12] = true;
		else if (s[1] == 'K')
			cnt[ind][13] = true;
	}
	int ans = 0;
	for (int i = 1;i <= 4;i++) {
		for (int j = 1;j <= 13;j++)
			if (cnt[i][j])
				ans++;
	}
	cout << 52 - ans;
	return 0;
}
