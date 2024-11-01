#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
char a[1010][1010]={0};
long long int b[1010][1010]={0};
long long int dx[14]={+0,+1,+0,-1};
long long int dy[14]={+1,+0,-1,+0};
long long int flag=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	long long int t=0;
	cin>>t;
	long long int n=0,m=0,k=0;
	long long int x0=0,y0=0,d0=0;
	for(long long int j0=1;j0<=t;j0++)
	{
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		//long long int cur=n*m*10;
		for(long long int j1=1;j1<=n;j1++)
		{
			for(long long int j2=1;j2<=m;j2++)
			{
				cin>>a[j1][j2];
			}
		}
		memset(b,0,sizeof(b));
		b[x0][y0]=1;
		long long int geshu=1;
		long long int cishu=0;
		while(true)
		{
			cishu++;
			if(cishu>k)
			{
				break;
			}
			flag=0;
			long long int cx=x0+dx[d0];
			long long int cy=y0+dy[d0];
			if(cx>=1 && cx<=n && cy>=1 && cy<=m)
			{
				if(b[cx][cy]==1)
				{
					break;
				}
				if(a[cx][cy]=='x')
				{
					flag=1;
				}
				else
				{
					geshu++;
					b[cx][cy]=1;
					x0=cx;
					y0=cy;
				}
			}
			else
			{
				flag=1;
			}
			if(flag==1)
			{
				d0=(d0+1)%4;
			}
			//cout<<"x="<<x0<<" y="<<y0<<" d="<<d0<<endl;
			//cout<<"geshu="<<geshu<<endl;
		}
		cout<<geshu<<endl;
	}
    return 0;
}

