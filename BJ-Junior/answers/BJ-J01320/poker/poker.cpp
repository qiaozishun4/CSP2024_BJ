#include<iostream>
using namespace std;
int h[20][10];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		char hua,shu;
		cin>>hua>>shu;
		if(hua=='D')
		{
			if(shu=='A')h[1][1]++;
			else if(shu=='T')h[10][1]++;
			else if(shu=='J')h[11][1]++;
			else if(shu=='Q')h[12][1]++;
			else if(shu=='K')h[13][1]++;
			else
			{
				h[shu-'0'][1]++;
			}
		}
		if(hua=='C')
		{
			if(shu=='A')h[1][2]++;
			else if(shu=='T')h[10][2]++;
			else if(shu=='J')h[11][2]++;
			else if(shu=='Q')h[12][2]++;
			else if(shu=='K')h[13][2]++;
			else
			{
				h[shu-'0'][2]++;
			}
		}
		if(hua=='H')
		{
			if(shu=='A')h[1][3]++;
			else if(shu=='T')h[10][3]++;
			else if(shu=='J')h[11][3]++;
			else if(shu=='Q')h[12][3]++;
			else if(shu=='K')h[13][3]++;
			else
			{
				h[shu-'0'][3]++;
			}
		}
		if(hua=='S')
		{
			if(shu=='A')h[1][4]++;
			else if(shu=='T')h[10][4]++;
			else if(shu=='J')h[11][4]++;
			else if(shu=='Q')h[12][4]++;
			else if(shu=='K')h[13][4]++;
			else
			{
				h[shu-'0'][4]++;
			}
		}
	}
	int ans=52;
	for(int i=1;i<=13;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(h[i][j])ans--;
		}
	}
	cout<<ans;
	return 0;
}
