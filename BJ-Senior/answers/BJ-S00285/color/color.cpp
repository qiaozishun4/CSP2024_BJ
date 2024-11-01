#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int T;
int cl[25];
int a[25];
int ans;
int jieguo;
void calc()
{
	ans = 0;
	int ls1 = 0;
	int ls0 = 0;
	for(int i = 1;i <= n;i++)
	{
		if(cl[i] == 1)
		{
			if(a[i] == a[ls1]) ans += a[i];
			ls1 = i;
		}
		if(cl[i] == 0)
		{
			if(a[i] == a[ls0]) ans += a[i];
			ls0 = i;
		}
	}
	jieguo = max(jieguo,ans);
	return;
}
void dfs(int i)
{
	
	if(i == n)
	{
		calc();
		return;
	}
	cl[i + 1] = 0;
	dfs(i + 1);
	cl[i + 1] = 1;
	dfs(i + 1);
	return;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		dfs(0);
		cout << jieguo << endl;
	}
	
	
	return 0;
}
