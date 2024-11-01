#include <iostream>
using namespace std;
const int N=1e3+5;
const int lx[4]={0,1,0,-1};
const int ly[4]={1,0,-1,0};
long long T,ans;
long long n,m,k,xl,yl,dl;
char a[N][N];
void dfs(int x,int y,int d,long long step,long long point)
{
		if(step<=0)
		{
			ans=point;
			return ;
		}
		int flag=d-1;
		//cout<<x+lx[flag]<<" "<<y+ly[flag]<<" "<<step<<endl;
		while(x+lx[flag]<=0 || x+lx[flag]>m || y+ly[flag]<=0 || y+ly[flag]>n || a[x+lx[flag]][y+ly[flag]]!='.' )
		{
			//cout<<a[x+lx[flag]][y+ly[flag]]<<endl;
			  step--;
			  flag=(flag+1)%4;
			  if(a[x+lx[flag]][y+ly[flag]]=='.') break;
			  if(step<=0) return ;
		}
		dfs(x+lx[flag],y+ly[flag],flag,step-1,point+1);
		return ;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>xl>>yl>>dl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
			dfs(xl,yl,dl,k,1);
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=m;k++)
				{
					a[i][j]=char(0);
				}
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
