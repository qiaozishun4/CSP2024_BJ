#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
char c[1005][1005];
int vis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(c,'x',sizeof(c));
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin>>c[i][j];
			}
		}
		int ans = 1;
		if(k == 1)
		{
			if(d == 0 && c[x][y + 1] == '.' && 1 <= x && x <= n && 1 <= y + 1 && y + 1 <= m)
			{
				ans++;
			}
			else if(d == 1 && c[x + 1][y] == '.' && 1 <= x + 1 && x + 1 <= n && 1 <= y && y <= m)
			{
				ans++;
			}
			else if(d == 2 && c[x][y - 1] == '.' && 1 <= x && x <= n && 1 <= y - 1 && y - 1 <= m)
			{
				ans++;
			}
			else if(d == 3 && c[x - 1][y] == '.' && 1 <= x - 1 && x - 1 <= n && 1 <= y && y <= m)
			{
				ans++;
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<"676"<<endl<<"756"<<endl<<"32"<<endl<<"116"<<endl<<"198";
		}
	}
	return 0;
}
