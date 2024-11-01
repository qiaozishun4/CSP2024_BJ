#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char a[55] = {},b[55] = {};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> s;
		a[i] = s[0];
		b[i] = s[1];
	}
	int ans = 52 - n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j < i;j++)
		{
			if(a[i] == a[j] && b[i] == b[j])
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}