#include <bits/stdc++.h>
using namespace std;

int n,a[15],b[15],c[15],d[15],cnt1,cnt2,cnt3,cnt4;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		char x,y;
		cin >> x >> y;
		int t = 0;
		if (y == 'A') t = 1;
		else if (y == 'T') t = 10;
		else if (y == 'J') t = 11;
		else if (y == 'Q') t = 12;
		else if (y == 'K') t = 13;
		else t = y-'0';
		if (x == 'D')
		{
			a[t]++;
			if (a[t] == 1) cnt1++;
		}
		else if (x == 'C')
		{
			b[t]++;
			if (b[t] == 1) cnt2++;
		}
		else if (x == 'H')
		{
			c[t]++;
			if (c[t] == 1) cnt3++;
		}
		else 
		{
			d[t]++;
			if (d[t] == 1) cnt4++;
		} 
	}
	int k = cnt1+cnt2+cnt3+cnt4;
	cout << 52-k << "\n";
	
	return 0;
}
