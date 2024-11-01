#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[100];

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	sort(s + 1, s + n + 1);
	int ans = 52;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == s[i + 1])
		{
			continue;
		}
		ans--;
	}
	cout << ans << endl;
	return 0;
}