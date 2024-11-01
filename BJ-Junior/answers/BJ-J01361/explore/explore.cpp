//T1.cpp
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int dx,dy;
}a[4];
bool vis[1005][1005];
int T;
char ch[1005][1005];
int main()
{
	int i,j;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	a[0].dx=0;a[0].dy=1;
	a[1].dx=1;a[1].dy=0;
	a[2].dx=0;a[2].dy=-1;
	a[3].dx=-1;a[3].dy=0;
	while(T--)
	{
		memset(vis,false,sizeof(vis));
		int d,k,x,y,n,m,cnt=1;
		int dx,dy;
		cin>>n>>m>>k>>x>>y>>d;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>ch[i][j];
		dx=a[d].dx;dy=a[d].dy;
		vis[x][y]=true;
		while(k)
		{
			while(x+dx<1||x+dx>n||y+dy<1||y+dy>m||ch[x+dx][y+dy]=='x')
			{
				d=(d+1)%4;
				dx=a[d].dx;dy=a[d].dy;
				k--;
				if(!k)
					break;
			}
			if(!k)
				break;
			k--;
			x+=dx;y+=dy;
			if(!vis[x][y])
			{
				cnt++;
				vis[x][y]=true;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}