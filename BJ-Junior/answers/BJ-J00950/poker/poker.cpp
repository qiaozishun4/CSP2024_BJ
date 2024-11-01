#include<bits/stdc++.h>
using namespace std;
const int maxn = 13 + 1;
int n = 0, ans = 0;
string st;
bool d[maxn], c[maxn], h[maxn], s[maxn];
int DecodeSecond (string x) {
	if (x[1] == 'A') return 0;
	if (x[1] == '2') return 1;
	if (x[1] == '3') return 2;
	if (x[1] == '4') return 3;
	if (x[1] == '5') return 4;
	if (x[1] == '6') return 5;
	if (x[1] == '7') return 6;
	if (x[1] == '8') return 7;
	if (x[1] == '9') return 8;
	if (x[1] == 'T') return 9;
	if (x[1] == 'J') return 10;
	if (x[1] == 'Q') return 11;
	if (x[1] == 'K') return 12;
	return 13;
}
void DecodeFirst (string x) {
	if (x[0] == 'D') d[DecodeSecond(x)] = true;
	else if (x[0] == 'C') c[DecodeSecond(x)] = true;
	else if (x[0] == 'H') h[DecodeSecond(x)] = true;
	else if (x[0] == 'S') s[DecodeSecond(x)] = true;
}
int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	memset(d, 0, sizeof(d));
	memset(c, 0, sizeof(c));
	memset(h, 0, sizeof(h));
	memset(s, 0, sizeof(s));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st;
		DecodeFirst(st);
	}
	for (int i = 0; i < 13; i++) {
		if (!d[i]) ans++;
		if (!c[i]) ans++;
		if (!h[i]) ans++;
		if (!s[i]) ans++;
	}
	cout << ans << '\n';
	return 0;
}
