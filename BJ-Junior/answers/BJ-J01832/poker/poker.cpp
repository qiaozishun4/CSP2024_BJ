#include<iostream>
#include<string>
using namespace std;
int a[6][15];
int ans;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		a[(s[0] == 'D' ? 1 : (s[0] == 'C' ? 2 : (s[0] == 'H' ? 3 : 4)))][(s[1] >= '2' && s[1] <= '9' ? s[1] - 48 : (s[1] == 'A' ? 1 : (s[1] == 'T' ? 10 : (s[1] == 'J' ? 11 : (s[1] == 'Q' ? 12 : 13)))))] = 1;
	}
	for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= 13; j++)
			ans += (a[i][j] ? 0 : 1);
	cout << ans;
	return 0;
}
