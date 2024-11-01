#include <bits/stdc++.h>
using namespace std;
int poker[30][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	int i,j,k,n,m,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		char p1,p2;
		cin>>p1>>p2;
		int col,num;
		if(p1=='D') col=1;
		if(p1=='C') col=2;
		if(p1=='H') col=3;
		if(p1=='S') col=4;
		if(p2=='T') num=10;
		else if(p2=='A') num=1;
		else if(p2=='J') num=11;
		else if(p2=='Q') num=12;
		else if(p2=='K') num=13;
		else num=p2-'0';
		poker[col][num]++;
	}
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=13;j++)
		{
			if(!poker[i][j]) ans++;
		}
	}
	cout<<ans;

}
