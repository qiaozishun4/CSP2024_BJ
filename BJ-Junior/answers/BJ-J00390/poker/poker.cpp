#include <bits/stdc++.h>
using namespace std;
bool p[10][20];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char a,b;
	int n,a1,b1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(a=='D') a1=1;
		if(a=='C') a1=2;
		if(a=='S') a1=4;
		if(a=='H') a1=3;
		if(b=='A') b1=1;
		if(b=='2') b1=2;
		if(b=='3') b1=3;
		if(b=='4') b1=4;
		if(b=='5') b1=5;
		if(b=='6') b1=6;
		if(b=='7') b1=7;
		if(b=='8') b1=8;
		if(b=='9') b1=9;
		if(b=='T') b1=10;
		if(b=='J') b1=11;
		if(b=='Q') b1=12;
		if(b=='K') b1=13;
		p[a1][b1]=1;
	}
	for(int i=1;i<=4;i++) for(int j=1;j<=13;j++) if(p[i][j]==1) ans++;
	cout<<52-ans;
	return 0;
}
