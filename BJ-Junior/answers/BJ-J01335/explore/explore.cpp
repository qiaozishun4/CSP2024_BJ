#include <iostream>
#include <cstring>
using namespace std;
const int N=1003;
char a[N][N];
bool v[N][N];
int t,n,m,p,ans;
struct node{
	int x,y,d;
};
node fwd(node x)
{
	if (x.d==0)
		x.y++;
		
	if (x.d==1)
		x.x++;
		
	if (x.d==2)
		x.y--;
		
	if (x.d==3)
		x.x--;
	return x;
}
bool chk(node x)
{
	if (x.x<1 || x.y<1 || x.x>n || x.y>m || a[x.x][x.y]=='x') return 0;
	return 1;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	node f;
	cin>>t;
	while (t--)
	{
		memset(v,0,sizeof(v));
		ans=1;
		cin>>n>>m>>p>>f.x>>f.y>>f.d;
		v[f.x][f.y]=1;
		for (int i=1;i<=n;i++)
		{
			getchar();
			for (int j=1;j<=m;j++)
			{
				a[i][j]=getchar();
//cin>>a[i][j];
			}
		}
		for (int i=1;i<=p;i++)
		{
			if (chk(fwd(f)))
			{
				f=fwd(f);
				if (!v[f.x][f.y]){
					ans++;
					v[f.x][f.y]=1;
				}
			}
			else
			{
				f.d=(f.d+1)%4;
			}
//			cout<<f.d<<' '<<f.x<<' '<<f.y<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}