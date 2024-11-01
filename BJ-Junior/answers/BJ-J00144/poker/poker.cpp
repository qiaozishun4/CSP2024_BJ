#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int n, tmp, ans;
string s;
bool vis[N];
int Char_To_Int (char c)
{
	if (c >= '2' && c <= '9')
		return c - '0';
	if (c == 'A')
		return 1;
	if (c == 'T')
		return 10;
	if (c == 'J')
		return 11;
	if (c == 'Q')
		return 12;
	return 13;
}
int main ()
{
	freopen ("poker.in", "r", stdin);
	freopen ("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		tmp = 0;
		cin >> s;
		if (s[0] == 'C')
			tmp += 13;
		else if (s[0] == 'H')
			tmp += 26;
		else if (s[0] == 'S')
			tmp += 39;
		vis[tmp + Char_To_Int (s[1])] = 1;
		//cout << "num: " << tmp + Char_To_Int (s[1]) << endl;
	}
	for (int i = 1; i <= 52; i++)
		if (vis[i] == 0)
			ans++;
	cout << ans << endl;
	return 0;
}