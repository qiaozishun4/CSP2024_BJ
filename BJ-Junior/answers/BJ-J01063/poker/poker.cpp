#include<iostream>
using namespace std;
int n;
bool vis[5][15];
int idhua(char c)
{
	switch (c) {
	case 'C':
		return 1;
	case 'D':
		return 2;
	case 'H':
		return 3;
	case 'S':
		return 4;
	}
}
int iddian(char c)
{
	if ('0' <= c && c <= '9')
		return c - '0';
	if (c == 'A')
		return 1;
	if (c == 'T')
		return 10;
	if (c == 'J')
		return 11;
	if (c == 'Q')
		return 12;
	if (c == 'K')
		return 13;
}
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		char hua, dian;
		cin >> hua >> dian;
		if (vis[idhua(hua)][iddian(dian)] == false) {
			vis[idhua(hua)][iddian(dian)] = true;
			ans++;
		}
	}
	cout << 52 - ans << endl;
	return 0;
}