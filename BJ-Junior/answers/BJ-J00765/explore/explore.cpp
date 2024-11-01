#include<bits/stdc++.h>
using namespace std;
int t;
char a[1002][1002];
int b[1002][1002];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		memset(b,0,sizeof(b));
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int wx,wy,d;
		scanf("%d%d%d",&wx,&wy,&d);
		int ans=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%s",a[j]+1);
		}
		b[wx][wy]=1;
		for(int j=1;j<=k;j++)
		{
			int s=wx,w=wy;
			if(d==0)wy++;
			if(d==1)wx++;
			if(d==2)wy--;
			if(d==3)wx--;
			if((1<=wx&&wx<=n)&&(1<=wy&&wy<=m))
			{
				if(a[wx][wy]=='.')
				{
					if(!b[wx][wy])
					{
						b[wx][wy]=1;
						ans++;
					}
				}
				else
				{
					d=(d+1)%4;
					wx=s;
					wy=w;
				}
			}
			else
			{
				d=(d+1)%4;
				wx=s;
				wy=w;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
