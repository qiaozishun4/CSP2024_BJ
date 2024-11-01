#include <bits/stdc++.h>
using namespace std;
//正解暂时还没想出来，先写部分分吧
int g[105]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		int x;
		cin>>x;
		if (x%7==0) for (int j=1;j<=x/7;j++) cout<<8;
		else if (x<=50) cout<<g[x];
		else if (x%7==1)
		{
			cout<<10;
			for (int i=1;i<=((x-1)/7)-1;i++) cout<<8;
		}
		else cout<<2888888888ll;
		cout<<endl;
	}
	return 0;
}
