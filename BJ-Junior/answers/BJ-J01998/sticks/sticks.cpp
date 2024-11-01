#include <iostream>
using namespace std;

int a[100005];
int ans[55];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int num;
		cin >> num;
		bool b = 0;
		for (int j = 1;j <= 1e6;j++)
		{
			int cnt = 0,k = j;
			while (k != 0)
			{
				int l = k % 10;
				k /= 10;
				if (l == 0)
				{
					cnt+=6;
				}
				else if (l == 1)
				{
					cnt+=2;
				}
				else if (l == 2)
				{
					cnt+=5;
				}
				else if (l == 3)
				{
					cnt+=5;
				}
				else if (l == 4)
				{
					cnt+=4;
				}
				else if (l == 5)
				{
					cnt+=5;
				}
				else if (l == 6)
				{
					cnt+=6;
				}
				else if (l == 7)
				{
					cnt+=3;
				}
				else if (l == 8)
				{
					cnt+=7;
				}
				else if (l == 9)
				{
					cnt+=6;
				}
			}
			if (cnt == num)
			{
				b = 1;
				ans[i] = j;
				break;
			}
		}
		if (!b)
		{
			ans[i] = -1;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}