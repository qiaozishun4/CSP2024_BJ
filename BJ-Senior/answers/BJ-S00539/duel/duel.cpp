#include<bits/stdc++.h>
using namespace std;
int a[100005];
int h[100005];
int v[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	int maxx = 1;
	h[1]++;
	for(int i = 2;i <= n;i++)
	{
		int x = i - 1;
		if(a[i] > a[x])
			h[++maxx]++;
		else
			h[maxx]++;
	}
	for(int i = 1;i <= maxx;i++)
	{
		v[i] = h[i];
	}
	for(int i = 2;i <= maxx;i++)
	{
		for(int j = 1;j < i;j++)
		{
			if(v[i] == 0)
				break;
			if(v[i] >= h[j])
			{	
				v[i] -= h[j];
				h[j] = 0;
			}
			else
			{
				h[j] -= v[i];
				v[i] = 0;
			}
		}
	}
	int sum = 0;
	for(int i = 1;i <= maxx;i++)
	{
		sum += h[i];
	}
	cout << sum;
	return 0;
}
