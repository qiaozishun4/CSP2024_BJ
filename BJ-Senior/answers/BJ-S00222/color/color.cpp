#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=200010,MAXA=1000010;
int n,s;
int a[MAXN];
int c[MAXN];
int lx[MAXA];
long long ans=0;
long long dp[MAXN][2];

long long Max(long long x,long long y)
{
	if(x>y) return x;
	return y;
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=s;i++) c[i]=a[i]=dp[i][0]=dp[i][1]=0;
		for(int i=1;i<=MAXA-10;i++) lx[i]=0;
		ans=s=0;
		cin>>n;
//		for(int i=1;i<=n;i++) cout<<a[i]<<dp[i][1]<<dp[i][0];
//		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(a[s]!=x) a[++s]=x;
			else {ans+=x; continue;}
			c[s]=lx[a[s]];
			lx[a[s]]=s;
		}
//		cout<<ans<<"   ";
		for(int i=1;i<=s;i++)
		{
		//[0] chosen [1] not chosen
		//	cout<<i<<' '<<c[i]<<"c ";
			if(!c[i])
			{
				dp[i][0]=0;
				dp[i][1]=Max(dp[i-1][0],dp[i-1][1]);
		//		cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
				continue;
			}
			dp[i][1]=Max(dp[i-1][0],dp[i-1][1]);
			dp[i][0]=a[i]+Max(dp[c[i]+1][0],dp[c[i]+1][1]);
		//	cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
		}
		ans+=Max(dp[s][1],dp[s][0]);
		cout<<ans<<endl;
	}
	return 0;
}
/*
15
1 12 11 7 11 15 6 4 6 3 15 7 5 2
*/
