#include <bits/stdc++.h>
using namespace std;
bool a[110][110];
int main()
{
	freopen("poker.in" , "r" , stdin);
	freopen("poker.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		char x , y;
		cin >> x >> y;
		if('2' <= y && y <= '9')
			a[x - 'A'][y - '0'] = true;
		else
		{
			if(y == 'A')
				a[x - 'A'][1] = true;
			if(y == 'T')
				a[x - 'A'][10] = true;
			if(y == 'J')
				a[x - 'A'][11] = true;
			if(y == 'Q')
				a[x - 'A'][12] = true;
			if(y == 'K')
				a[x - 'A'][13] = true;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= 13 ; i ++)
	{
		if(a['C' - 'A'][i] == false)
			ans ++;
	}
	for(int i = 1 ; i <= 13 ; i ++)
	{
		if(a['H' - 'A'][i]== false)
			ans ++;
	}
	for(int i = 1 ; i <= 13 ; i ++)
	{
		if(a['D' - 'A'][i] == false)
			ans ++;
	}
	for(int i = 1 ; i <= 13 ; i ++)
	{
		if(a['S' - 'A'][i] == false)
			ans ++;
	}
	cout << ans << endl;
	return 0;
}
