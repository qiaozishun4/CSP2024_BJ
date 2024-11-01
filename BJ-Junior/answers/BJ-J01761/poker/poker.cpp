#include<bits/stdc++.h>
using namespace std;
bool a[100005];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	char x,y;
	int g,h,k;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		g=int(x),h=int(y);
		k=g*100+h;
		if(a[k]==0) ans++;
		a[k]=1;
	}
	cout<<52-ans;
	return 0;
}
