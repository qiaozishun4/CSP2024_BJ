#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char num[] = {'0', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
bool vis[5][15];

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		int j;
		for(j = 1; j <= 13; j++) if(num[j] == s[1]) break;
		if(s[0] == 'D') vis[1][j] = true;
		if(s[0] == 'C') vis[2][j] = true;
		if(s[0] == 'H') vis[3][j] = true;
		if(s[0] == 'S') vis[4][j] = true;
	}
	
	int ans = 0;
	for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= 13; j++)
			if(!vis[i][j]) ans++;
	cout << ans << endl;
	return 0;
}
