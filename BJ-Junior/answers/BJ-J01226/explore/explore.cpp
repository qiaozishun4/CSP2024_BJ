#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
map<string ,int >mp;
char s[1005][1005];
int n,m;
int mm[5];
int a[8][4]={{0,1},{1,0},{0,-1},{-1,0}};
bool check(int nx,int ny)
{
	if(nx<1||nx>n||ny<1||ny>m||s[nx][ny]=='x')
		return false;
	return true;
	
}
int main()
{
	
	freopen("explore.in","w",stdin);
	freopen("explore.out","r",stdout);
	int npc=0,t,k,nx,ny,ans,sx,sy,d;
	cin>>t;
	while(t--)
	{
		ans=1;
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>s[i][j];
		while(k--)
		{
			nx=sx+a[d][0];
			ny=sy+a[d][1];
			s[sx][sy]='@';
			if(check(nx,ny))
			{
				sx=nx;
				sy=ny;
				if(s[nx][ny]!='@')
				{
					
					ans++;
				}
			}
			else
			{
				d=(d+1)%4;
			}
		}
		//cout<<ans<<endl;
		mm[npc++]=ans;
		
		
		
		
	}	
	for(int i=0;i<npc;i++)
		cout<<mm[i]<<endl;
	return 0;
}
