#include<bits/stdc++.h>
using namespace std;
const int N=4,M=13;
int n;
bool flag[N+5][M+5];
string s;
char a1[N+5]={' ','D','C','H','S'},a2[M+5]={' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int ans;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int val1=0,val2=0;
		for(int j=1;j<=N;j++)
		{
			if(s[0]==a1[j])
			{
				val1=j;
				break;
			}
		}
		for(int j=1;j<=M;j++)
		{
			if(s[1]==a2[j])
			{
				val2=j;
				break;
			}
		}
		flag[val1][val2]=1;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(!flag[i][j])
			{
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}