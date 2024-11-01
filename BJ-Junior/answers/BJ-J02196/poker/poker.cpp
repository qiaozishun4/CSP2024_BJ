#include<iostream>
using namespace std;
bool a[55];
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n;i++)
	{
		string s;
		cin >> s;
		char x = s[0], y = s[1];
		int yy = 0;
		if(y == 'A') yy = 1;
		else if(y == 'T') yy = 10;
		else if(y == 'J') yy = 11;
		else if(y == 'K') yy = 12;
		else if(y == 'Q') yy = 13;
		else yy = (int)(y - '0');
		if(x == 'D') a[yy] = 1;
		else if(x == 'C') a[13 + yy] = 1;
		else if(x == 'H') a[26 + yy] = 1;
		else a[39 + yy] = 1;
	}
	int cnt = 0;
	for(int i = 1; i <= 52;i++)
	{
		if(a[i] == 0) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
