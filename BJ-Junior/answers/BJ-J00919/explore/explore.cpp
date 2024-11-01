#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int st[1010][1010],a[10],top;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,k,ii,jj,d,ans;
string s;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(st,0,sizeof(st));
		cin>>n>>m>>k>>ii>>jj>>d;
		for(int i=1;i<=n;i++) 
		{
			string s;
			cin>>s;
			for(int j=1;j<=m;j++) c[i][j]=s[j-1];
		}
		st[ii][jj]=true;
		ans=1;
		for(int i=1;i<=k;i++)
		{
			int xx=ii+dx[d],yy=jj+dy[d];
			if(xx>0 && xx<=n && yy>0&& yy<=m && c[xx][yy]!='x')
			{
				ii=xx,jj=yy;
				if(!st[ii][jj]) st[ii][jj]=1,ans++;
			}
			else d=(d+1)%4;
		}
		//cout<<ans<<endl;
		a[++top]=ans;
	}
	for(int i=1;i<=top;i++) cout<<a[i]<<endl;
	return 0;
}
