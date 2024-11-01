#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,X[4]={0,1,0,-1},Y[4]={1,0,-1,0};
int n,m,k,x,y,d,mp[N][N],ans;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(mp,0,sizeof(mp));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			mp[i][0]=-1;
			mp[i][m+1]=-1;
		}
		for(int j=1;j<=m;j++)
		{
			mp[0][j]=-1;
			mp[n+1][j]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			string w;
			cin>>w;
			for(int j=0;j<m;j++)
			{
				if(w[j]=='x')
				{
					mp[i][j+1]=-1;
				}
			}
		}
		ans=1;
		mp[x][y]=1;
		while(k--)
		{
			if(mp[x+X[d]][y+Y[d]]==-1)
			{
				d++;
				d%=4;
			}
			else
			{
				if(!mp[x+X[d]][y+Y[d]])
				{
					ans++;
					mp[x+X[d]][y+Y[d]]=1;
				}
				x+=X[d];
				y+=Y[d];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}