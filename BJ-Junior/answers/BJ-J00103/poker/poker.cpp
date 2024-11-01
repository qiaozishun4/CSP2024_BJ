#include <bits/stdc++.h>
using namespace std;
char f[5];
int g[10][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,s,t,m=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f;
		if(f[0]=='D')
			s=1;
		if(f[0]=='C')
			s=2;
		if(f[0]=='H')
			s=3;
		if(f[0]=='S')
			s=4;
		if(f[1]=='A')
			t=1;
		else if(f[1]=='T')
			t=10;
		else if(f[1]=='J')
			t=11;
		else if(f[1]=='Q')
			t=12;
		else if(f[1]=='K')
			t=13;
		else
			t=f[1]-'0';
		g[s][t]++;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!g[i][j])
			{
				m++;
				//cout<<i<<" "<<j<<endl;
			}
	cout<<m;
	return 0;
}