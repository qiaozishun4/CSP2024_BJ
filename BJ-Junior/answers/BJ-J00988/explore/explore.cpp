#include<iostream>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		char a[n+3][m+3];
		bool p[n+3][m+3]={0};
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		cin>>a[i][j];
		int cnt=1;
		for(int o=1;o<=k;o++)
		{
			if(d==0)
			{
				if((a[x][y+1]=='x')||(y+1>m)) d=(d+1)%4;
				else {y++;if(p[x][y]!=1)cnt++;}
			}
			else if(d==1)
			{
				if((a[x+1][y]=='x')||(x+1>n)) d=(d+1)%4;
				else {x++;if(p[x][y]!=1)cnt++;}
			}
			
			else if(d==2)
			{
				if((a[x][y-1]=='x')||(y-1<1)) d=(d+1)%4;
				else {y--;if(p[x][y]!=1)cnt++;}
			}
			else if(d==3)
			{
				if((a[x-1][y]=='x')||(x-1<1)) d=(d+1)%4;
				else {x--;if(p[x][y]!=1)cnt++;}
			}
			p[x][y]=1;
		}
		
		cout<<cnt<<"\n";
	}
    return 0;
}
