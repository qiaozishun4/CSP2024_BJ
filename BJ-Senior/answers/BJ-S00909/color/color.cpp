#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int h[1000010];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=1000000;i++)
			h[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			h[a[i]]++;
		}
		int ans=0;
		for(int i=1;i<=1000000;i++)
			if(h[i]>0)
				ans=ans+(h[i]/2)*i;
		cout<<ans<<endl;
	}
	return 0;
}
