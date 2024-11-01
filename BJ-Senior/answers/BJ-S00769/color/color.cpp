#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int T,n,ans[N][2],cl[N],a[N],f[2001][2001][2][2];//0r,1b
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]==a[j])
				{
					cl[i]=j;
					break;
				}
			}
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(i==j+1)
				{
					f[i][j][0][1]=ans[i][1],f[i][j][1][0]=ans[i][0];
					f[i][j][0][0]=ans[j][0]+(a[i]==a[j]?a[i]:0);
					f[i][j][1][1]=ans[j][1]+(a[i]==a[j]?a[i]:0);
				}
				else
				{
					if(cl[i]==i-1)	f[i][j][0][1]+=a[i],f[i][j][1][0]+=a[i];
					f[i][j][0][1]+=f[i-1][j][0][1],f[i][j][1][0]+=f[i-1][j][1][0];
					f[i][j][0][0]=f[i-1][j][0][1]+(a[i]==a[j]?a[i]:0);
					f[i][j][1][1]=f[i-1][j][1][0]+(a[i]==a[j]?a[i]:0);
				}
				ans[i][0]=max(f[i][j][0][0],ans[i][0]);
				ans[i][0]=max(f[i][j][1][0],ans[i][0]);
				ans[i][1]=max(f[i][j][1][1],ans[i][1]);
				ans[i][1]=max(f[i][j][0][1],ans[i][1]);
				if(i==j+1)	f[i][j][0][1]=ans[i][1],f[i][j][1][0]=ans[i][0];
				res=max(res,ans[i][1]);
				res=max(res,ans[i][0]);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
