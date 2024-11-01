#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
char a[4]={'D','C','H','S'},b[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
bool ss[4][13];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x,y;
		cin>>x>>y;
		ss[x][y]=1;
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<13;j++)
		{
			if(!ss[a[i]][b[j]])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}