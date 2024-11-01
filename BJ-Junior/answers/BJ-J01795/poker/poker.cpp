#include <iostream>
#include <cstdio>
using namespace std;

int book[4][13];
int n, ans = 0;

void cal(char ch, int x) {
	if (ch == 'A') book[x][0]++;
	if (ch == '2') book[x][1]++;
	if (ch == '3') book[x][2]++;
	if (ch == '4') book[x][3]++;
	if (ch == '5') book[x][4]++;
	if (ch == '6') book[x][5]++;
	if (ch == '7') book[x][6]++;
	if (ch == '8') book[x][7]++;
	if (ch == '9') book[x][8]++;
	if (ch == 'T') book[x][9]++;
	if (ch == 'J') book[x][10]++;
	if (ch == 'Q') book[x][11]++;
	if (ch == 'K') book[x][12]++;
}

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (s[0] == 'D')
			cal(s[1], 0);
		else if (s[0] == 'C')
			cal(s[1], 1);
		else if (s[0] == 'H')
			cal(s[1], 2);
		else if (s[0] == 'S')
			cal(s[1], 3);
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			if (!book[i][j]) ans++;
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}