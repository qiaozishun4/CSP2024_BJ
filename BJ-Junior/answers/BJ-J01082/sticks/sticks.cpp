#include <bits/stdc++.h>
using namespace std;
int ans[10]={0,-1,1,7,4,2,6,8,10},st[7]={10,18,22,20,28,68,88};
/*
string ans[100005];
string mymin(string a,string b)
{
	if (a.size()<b.size())
		return a;
	if (b.size()<a.size())
		return b;
	if (a<b)
		return a;
	return b;
}
*/
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	/*
	ans[2]="1";
	ans[3]="7";
	ans[4]="4";
	ans[5]="2";
	ans[6]="0";
	ans[7]="8";
	ans[8]="10";
	for (int i=9;i<=100;i++)
	{
		ans[i]='1'+ans[i-2];
		ans[i]=mymin(ans[i],"2"+ans[i-5]);
		ans[i]=mymin(ans[i],"4"+ans[i-4]);
		ans[i]=mymin(ans[i],"6"+ans[i-6]);
		ans[i]=mymin(ans[i],"7"+ans[i-3]);
		ans[i]=mymin(ans[i],"8"+ans[i-7]);
		cout<<ans[i]<<"\n";
	}
	*/
	int T,n;
	cin>>T;
	while (T--)
	{
		cin>>n;
		if (n<=8)
		{
			cout<<ans[n]<<"\n";
			continue;
		}
		cout<<st[(n-8)%7];
		for (int i=0;i<(n-8)/7;i++)
			cout<<8;
		cout<<"\n";
	}
	return 0;
}
