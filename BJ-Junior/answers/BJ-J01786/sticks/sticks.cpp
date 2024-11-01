#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
//string dp[N] = {"0","0","1","7","4","2","6","8"};
int shi[N];
int ans[N] = {0,0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		if (n == 1)
		{
			printf("-1\n");
			continue;
		}
		if (n % 7 == 0)
		{
			for (int i = 1;i <= n/7;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		else if (n % 7 == 1)
		{
			printf("10");
			for (int i = 1;i <= (n-1)/7-1;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		else
		{
			if (n <= 20)
			{
				printf("%d\n",ans[n]);
			}
			else
			{
				printf("%d",ans[n%7+7]);
				for (int i = 1;i <= n/7-1;i++)
				{
					printf("8");
				}
				printf("\n");
			}
			//int wei = (n-1)/7+1;
//			for (int i = 1;i <= wei;i++)
//			{
//				for (int j = 1;j <= n;i++)
//				{
//					if (j == 1)
//					{
//						dp[i][1] = num[i];
//					}
//				}
//			}
//			for (int i = 8;i <= n;i++)
//			{
//				for (int j = 1;j <= 9;j++)
//				{
//					//cout<<"i="<<i<<",j="<<j<<","<<"j*shi[(i-1)/7]+dp[i-num[j]]="<<j*shi[(i-1)/7]<<"+"<<dp[i-num[j]]<<"="<<j*shi[(i-1)/7]+dp[i-num[j]]<<'\n';
//					dp[i] = min(dp[i],dp[i-num[j]]);
//				}
//			}
//			printf("%s\n",dp[n]);
		}
	}
	return 0;
}
