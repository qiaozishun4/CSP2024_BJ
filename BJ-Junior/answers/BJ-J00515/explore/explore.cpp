#include<bits/stdc++.h>
using namespace std;
char mp[1010][1010];
bool vis[1011][1011];
int n,m,k,a,b,d,na,nb;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,cnt=0;
	cin>>t;
	while(t--)
	{
		cnt=1;
		cin>>n>>m>>k>>a>>b>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
				vis[i][j]=false;
			}
		}
		
		vis[a][b]=true;
		for(int i=1;i<=k;i++)
		{
			na=a+dx[d],nb=b+dy[d];
			if(na>=1&&na<=n&&nb>=1&&nb<=m&&mp[na][nb]=='.')
			{
				if(!vis[na][nb])
				{
					vis[na][nb]=true;
					cnt++;
				}
				a=na,b=nb;
				//cout<<a<<" "<<na<<" "<<b<<" "<<nb<<" "<<d<<" "<<i<<endl;
			}
			else d=(d+1)%d;
		}
		cout<<cnt<<endl;
	}
    return 0;
}