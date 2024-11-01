#include <bits/stdc++.h>
using namespace std;

int n,ans = 52;
bool f[5][15];

int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		char a,b;
		int x,y;
		cin >> a >> b;
		if (a == 'D') x = 1;
		if (a == 'C') x = 2;
		if (a == 'H') x = 3;
		if (a == 'S') x = 4;
		if (b >= '2' && b <= '9') y = b - '0';
		if (b == 'A') y = 1;
		if (b == 'T') y = 10;
		if (b == 'J') y = 11;
		if (b == 'Q') y = 12;
		if (b == 'K') y = 13;
		if (!f[x][y]) ans--;
		f[x][y] = 1;
	}
	cout << ans << endl;
	return 0;
}