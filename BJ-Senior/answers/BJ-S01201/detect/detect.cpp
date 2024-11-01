#include <bits/stdc++.h>
using namespace std;
int d[1000005];
int v[1000005];
int a[1000005];
int p[1000005];
int pv[1005][1005];
int vis[1000005];
int box[1000005];
int minx=999999999;
int n,m;
void dfs(int cur)
{
	if (cur>m)
	{
		int c=0;
		int sum=0;
		for (int i=1;i<=m;i++)
		{
			sum+=box[i];
			if (!box[i]) continue;
			for (int j=1;j<=n;j++)
			{
				if (!vis[pv[i][j]])  c++;
				vis[pv[i][j]]=1;
			}
		}
		if (c==n) minx=min(minx,sum);
	}
	for (int i=0;i<=1;i++)
	{
		box[cur]=i;
		dfs(cur+1);
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		int L,V;
		cin>>n>>m;
		cin>>L>>V;
//		bool flag=true;
		for (int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
//			if (a[i]) flag=false;
		}
		for (int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
/*		if (flag)
		{
			int sum=0;
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=m;j++)
				{
					if (d[i]>=p[j]&&v[i]>=V)
					{
						sum++;
					}
				}
			}
		}*/
//		else if (n<=10)
//		{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				int s=p[j]-d[i];
				if (d[i]>=p[j]&&/*到达p[j]时的瞬速度是否>=V*/sqrt(v[i]*v[i]+2*a[i]*s)>=double(V))
				{
					sum++;
					pv[i][j]=1;
				}
			}
		}
		dfs(1);
		cout<<sum<<" "<<minx<<endl;
//		}
		
	}
	return 0;
}
