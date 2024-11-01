#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
char td[100009][1009];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	int x,y,d;
	for(int i=1;i<=t;i++) 
	{
		int sum=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++) for(int o=1;o<=m;o++) cin>>td[j][o];
		td[x][y]='q';
		for(int j=0;j<k;j++)
		{
			if(d==0&&(y+1)<=m&&td[x][y+1]!='x') y=y+1;
			else if(d==1&&(x+1)<=n&&td[x+1][y]!='x') x=x+1;
			else if(d==2&&(y-1)>=1&&td[x][y-1]!='x') y=y-1;
			else if(d==3&&(x-1)>=1&&td[x-1][y]!='x') x=x-1;
			else d=((d+1)%4);
			td[x][y]='q';
			//cout<<"x:"<<x<<" y"<<y<<" d"<<d<<endl;
		}
		for(int j=1;j<=n;j++) 
		{
			for(int o=1;o<=m;o++) 
			{
				//cout<<td[j][o]<<" ";
				if(td[j][o]=='q') sum++;
			}
			//cout<<endl;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
