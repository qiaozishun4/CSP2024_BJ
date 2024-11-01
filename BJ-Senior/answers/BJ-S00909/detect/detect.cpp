#include<bits/stdc++.h>
using namespace std;
int n,m,l,v;
int a[100010],b[100010],c[100010],p[100010];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=m;i++)
			cin>>p[i];
		sort(p+1,p+m+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>p[m])
				a[i]=0;
			if(b[i]>v)
				ans++;
		}
		cout<<ans<<" ";
		if(ans==0) cout<<m<<endl;
		else cout<<m-1<<endl;
	}
	return 0;
}
