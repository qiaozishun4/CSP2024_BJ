#include<bits/stdc++.h>
using namespace std;
bool col[20];
int t,n,a[200010];
long long dp[2010][2010],tmp,ans;
void solve1()
{
	int num1=0,num2=0;
	long long tans=0;
	ans=0;
	for(int st=0;st<(1<<n);st++)
	{
		num1=0,num2=0,tans=0;
		for(int i=1;i<=n;i++)
		{
			if(((1<<(i-1))^st)<=st&&st!=0) col[i]=1;
			else col[i]=0;
		}	
		for(int i=1;i<=n;i++)
		{
			if(col[i])
			{
				if(num1==a[i]) tans+=a[i];
				num1=a[i];
			}
			else
			{
				if(num2==a[i]) tans+=a[i];
				num2=a[i];
			}
		}
		ans=max(ans,tans);
	}
	cout<< ans<< endl;
}
void solve2()
{
for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=0;
	ans=0;
	dp[1][0]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i-1;j++)
		{
			if(a[i]==a[j]&&j!=0) tmp=a[j];
			else tmp=0;
			if(a[i]==a[i-1]) dp[i][j]=a[i]+dp[i-1][j];
			else dp[i][j]=dp[i-1][j];
			dp[i][i-1]=max(dp[i][i-1],dp[i-1][j]+tmp);	
		}
	}
	for(int i=0;i<n;i++) ans=max(ans,dp[n][i]);
	cout<< ans<< endl;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t--)
	{
	ans=0;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		if(n<=15) solve1();
		else solve2();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}