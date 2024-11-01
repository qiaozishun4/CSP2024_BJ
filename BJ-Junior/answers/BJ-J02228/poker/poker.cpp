#include<bits/stdc++.h>
using namespace std;
int h[255][255];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char c[5];
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c[0]=='D')
		{
			if(c[1]=='A') h[1][1]++;
			else if(c[1]=='2') h[1][2]++;
			else if(c[1]=='3') h[1][3]++;
			else if(c[1]=='4') h[1][4]++;
			else if(c[1]=='5') h[1][5]++;
			else if(c[1]=='6') h[1][6]++;
			else if(c[1]=='7') h[1][7]++;
			else if(c[1]=='8') h[1][8]++;
			else if(c[1]=='9') h[1][9]++;
			else if(c[1]=='T') h[1][10]++;
			else if(c[1]=='J') h[1][11]++;
			else if(c[1]=='Q') h[1][12]++;
			else if(c[1]=='K') h[1][13]++;
		}
		if(c[0]=='C')
		{
			if(c[1]=='A') h[2][1]++;
			else if(c[1]=='2') h[2][2]++;
			else if(c[1]=='3') h[2][3]++;
			else if(c[1]=='4') h[2][4]++;
			else if(c[1]=='5') h[2][5]++;
			else if(c[1]=='6') h[2][6]++;
			else if(c[1]=='7') h[2][7]++;
			else if(c[1]=='8') h[2][8]++;
			else if(c[1]=='9') h[2][9]++;
			else if(c[1]=='T') h[2][10]++;
			else if(c[1]=='J') h[2][11]++;
			else if(c[1]=='Q') h[2][12]++;
			else if(c[1]=='K') h[2][13]++;
		}
		if(c[0]=='H')
		{
			if(c[1]=='A') h[3][1]++;
			else if(c[1]=='2') h[3][2]++;
			else if(c[1]=='3') h[3][3]++;
			else if(c[1]=='4') h[3][4]++;
			else if(c[1]=='5') h[3][5]++;
			else if(c[1]=='6') h[3][6]++;
			else if(c[1]=='7') h[3][7]++;
			else if(c[1]=='8') h[3][8]++;
			else if(c[1]=='9') h[3][9]++;
			else if(c[1]=='T') h[3][10]++;
			else if(c[1]=='J') h[3][11]++;
			else if(c[1]=='Q') h[3][12]++;
			else if(c[1]=='K') h[3][13]++;
		}
		if(c[0]=='S')
		{
			if(c[1]=='A') h[4][1]++;
			else if(c[1]=='2') h[4][2]++;
			else if(c[1]=='3') h[4][3]++;
			else if(c[1]=='4') h[4][4]++;
			else if(c[1]=='5') h[4][5]++;
			else if(c[1]=='6') h[4][6]++;
			else if(c[1]=='7') h[4][7]++;
			else if(c[1]=='8') h[4][8]++;
			else if(c[1]=='9') h[4][9]++;
			else if(c[1]=='T') h[4][10]++;
			else if(c[1]=='J') h[4][11]++;
			else if(c[1]=='Q') h[4][12]++;
			else if(c[1]=='K') h[4][13]++;
		}
	}
	int cnt=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(!h[i][j]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
