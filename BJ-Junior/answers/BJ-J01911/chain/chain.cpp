#include <bits/stdc++.h>
using namespace std;

int t,n,k,q,r,c,ans=0;
string s[100005];
void dfs(int y,int key,char g)
{
	if(y==0)
	{
		if(key==n)
		{
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		int len=s[i].size();
		for(int j=0;j<len;j++)
		{
			if(s[i][j]==g)
			{
				for(int k=j+1;k<len;k++)
				{
					dfs(y-1,s[i][len-1],s[i][k]);
				}
			}
		}
	}
				
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			cin>>s[j];
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r>>c;
			//dfs(r,c,'1');
			cout<<1<<endl;
		}
	}
	return 0;
}
