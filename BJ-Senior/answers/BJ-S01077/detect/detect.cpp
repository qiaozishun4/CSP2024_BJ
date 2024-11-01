#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+7;
ll T,n,m,l,v;
struct node
{
	ll s,v1,v2;
};
node a[N],vis[N];
ll p[N],t[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(t,0,sizeof(t));
		cin>>n>>m>>l>>v;
		ll sum=0,ans1=0,ans2=0;
		bool f=0;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].s>>a[i].v1>>a[i].v2;
			if(a[i].v2==0)
			{
				sum++;
			}
		}
		ll maxn=0;
		for(ll i=1;i<=m;i++)
		{
			cin>>p[i];
			maxn=max(maxn,p[i]);
		}
		if(sum==n)
		{
			for(ll i=1;i<=n;i++)
			{
				if(a[i].v1>v&&a[i].s<=maxn)
				{
					ans1++;
					f=1;
				}
			}
			cout<<ans1<<' ';
			if(f)
			{
				cout<<(m-1);
			}
			else
			{
				cout<<m;
			}
			cout<<endl;
		}
		else
		{
			sort(p+1,p+m+1,greater<ll>());
			for(ll i=1;i<=n;i++)
			{
				if(a[i].s>maxn)
				{
					continue;
				}
				for(ll j=1;j<=m;j++)
				{
					if(a[i].s<=p[j])
					{
						ll dist=p[j]-a[i].s;
						double v3=sqrt(double(a[i].v1*a[i].v1+2.00*a[i].v2*dist));
						if(v3>v)
						{
							ans1++;
						}
						t[j]++;
						break;
					}
				}
			}
			cout<<ans1<<' ';
			for(ll i=1;i<=m;i++)
			{
				if(t[i]==0)
				{
					ans2++;
				}
			}
			cout<<ans2<<endl;
		}
	}
}
