#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[200005];
int box[200005];

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j];
			box[a[j]]++;
		}
		long long sum = 0;
		for (int j = 1; j <= 200005; j++)
		{
			if (box[j] > 1)
			{
				sum += (box[j] / 2) * j;
			}
		}
		cout << sum << endl;
		memset(box, 0, sizeof(box));
	}
	return 0;
}