#include <bits/stdc++.h>
using namespace std;

int cnt[10] = {6,2,5,5,4,5,6,3,7,6};
int t,n,a[55];

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n < 8)
		{
			if (n == 1) cout << -1;
			if (n == 2) cout << 1;
			if (n == 3) cout << 7;
			if (n == 4) cout << 4;
			if (n == 5) cout << 2;
			if (n == 6) cout << 6;
			if (n == 7) cout << 8;
			cout << "\n";
			continue;
		}
		if (n%7 == 1)
		{
			cout << "10";
			n -= 8;
		}
		else if (n%7 == 2) 
		{
			cout << "18";
			n -= 9;
		}
		else if (n%7 == 3)
		{
			cout << "22";
			n -= 10;
		}
		else if (n%7 == 4)
		{
			cout << "20";
			n -= 11;
		}
		else if (n%7 == 5)
		{
			cout << "28";
			n -= 12;
		}
		else if (n%7 == 6)
		{
			cout << "68";
			n -= 13;
		}
		while (n > 1)
		{
			cout << 8;
			n /= 7;
		}
		cout << "\n";
	}
	
	return 0;
}
