#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, bool> book;
int n, ans;
string s, k = " A23456789TJQK", p = " DCHS", now;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s;
		book[s] = true;
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 13; j++)
		{
			now = p[i];
			now += k[j];
			if(book[now] == false) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}