#include <bits/stdc++.h>

using namespace std;

int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int t, w;
	cin >> t;
	
	for (int j = 0; j < t; j ++ )
	{
		int n;
		cin >> n;
		if (n % 7 == 0) w = n / 7;
		else w = n / 7 + 1;
		
		for (int i = 1; ; i ++ )
		{
			int tmp = i, c = 0, ans = 0;
			
			while (tmp)
			{
				ans += a[tmp % 10];
				
				tmp /= 10;
				
				c ++ ;
			}
			
			if (ans == n)
			{
				cout << i << endl;
				
				break;
			}
			
			if (c > w)
			{
				cout << -1 << endl;
				
				break;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
