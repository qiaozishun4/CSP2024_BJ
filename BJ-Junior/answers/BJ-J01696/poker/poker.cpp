#include <iostream>
#include <map>

using namespace std;

const int maxn = 1e6 + 10;

int n;
string s1[] = { "$", "D", "C", "H", "S" };
string s2[] = { "$", "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K" };
map<string, int> mp;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		mp[str]++;
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
		{
			string s = s1[i] + s2[j];
			if (!mp[s]) ans++;
		}
	cout << ans << "\n";
	return 0;
}
