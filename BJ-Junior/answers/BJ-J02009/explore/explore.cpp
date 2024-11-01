#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,ans;
char str[1004][1004];
bool vis[1004][1004];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=0;i<n;i++) scanf("%s",str[i]);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=0;
		ans=0,x--,y--;
		while(k>=0)
		{
			if(!vis[x][y]) ans++,vis[x][y]=1;
			if(k==0) break;
			k--;
			if(d==0)
			{
				if(x>=0&&x<n&&y+1>=0&&y+1<m&&str[x][y+1]!='x') y++;
				else d=(d+1)%4;
			}
			else if(d==1)
			{
				if(x+1>=0&&x+1<n&&y>=0&&y<m&&str[x+1][y]!='x') x++;
				else d=(d+1)%4;
			}
			else if(d==2)
			{
				if(x>=0&&x<n&&y-1>=0&&y-1<m&&str[x][y-1]!='x') y--;
				else d=(d+1)%4;
			}
			else
			{
				if(x-1>=0&&x-1<n&&y>=0&&y<m&&str[x-1][y]!='x') x--;
				else d=(d+1)%4;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}