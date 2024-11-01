#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=2*1e5+2;
const int M=1e6+2;
int T,n;
int a[N];
int dp[N][2][2];//i,before red or blue
int ss[M];//last num
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T)
	{
		memset(ss,0,sizeof(ss));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",a+i);
			if(a[i]==a[i-1]) ss[i]+=a[i];
			ss[i]+=ss[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][0][0])+(a[i]==a[i-1]?a[i]:0);
			dp[i][1][1]=max(dp[i-1][1][0],dp[i-1][1][1])+(a[i]==a[i-1]?a[i]:0);
			for(int j=i-2;j>=1;j--)
			{
				dp[i][1][0]=max(dp[i][1][0],dp[j][1][0]+ss[i-1]-ss[j]+(a[i]==a[j]?a[i]:0)+(a[j+1]==a[j-1]?a[j-1]:0));
				dp[i][1][0]=max(dp[i][1][0],dp[j][1][1]+ss[i-1]-ss[j]+(a[i]==a[j]?a[i]:0));
				dp[i][0][1]=max(dp[i][0][1],dp[j][0][1]+ss[i-1]-ss[j]+(a[i]==a[j]?a[i]:0)+(a[j+1]==a[j-1]?a[j-1]:0));
				dp[i][0][1]=max(dp[i][0][1],dp[j][0][0]+ss[i-1]-ss[j]+(a[i]==a[j]?a[i]:0));
				//cout<<dp[i][0]<<endl;
			}
		}
		cout<<max(max(dp[n][0][1],dp[n][1][0]),max(dp[n][1][1],dp[n][0][0]))<<endl;
		T-=1;
	}
	return 0;
}