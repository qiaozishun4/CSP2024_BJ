#include <bits/stdc++.h>
using namespace std;
double d[100010],v[100010],a[100010],b[100010];
struct node
{
	int l,r;
}c[100010];
bool cmp(node x,node y)
{
	if(x.r!=y.r)
		return x.r<y.r;
	return x.l>y.l;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,i,la=0,ans,k=0;
		double L,V,o=0;
		cin>>n>>m>>L>>V;
		ans=m;
		for(i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(i=1;i<=m;i++)
			cin>>b[i];
		for(i=1;i<=n;i++)
		{
			if(a[i]>=o)
			{
				if(v[i]>V)
				{
					double x=d[i];
					int l=1,r=m;
					c[++k].l=m+1;
					c[k].r=m;
					while(l<=r)
					{
						int mid=(l+r)/2;
						if(b[mid]>=x)
						{
							c[k].l=mid;
							r=mid-1;
						}
						else
							l=mid+1;
					}
					if(c[k].r<c[k].l)
						k--;
				}
				else
				{
					if(a[i]==o)
						continue;
					double x=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
					int l=1,r=m;
					c[++k].l=0;
					c[k].r=m;
					while(l<=r)
					{
						int mid=(l+r)/2;
						if(b[mid]<=x)
						{
							c[k].l=mid;
							l=mid+1;
						}
						else
							r=mid-1;
					}
					c[k].l++;
					if(c[k].r<c[k].l)
						k--;
				}
			}
			else
			{
				if(v[i]<=V)
					continue;
				double x=d[i],y=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
				int l=1,r=m;
				c[++k].l=m+1;
				c[k].r=m+1;
				while(l<=r)
				{
					int mid=(l+r)/2;
					if(b[mid]>=x)
					{
						c[k].l=mid;
						r=mid-1;
					}
					else
						l=mid+1;
				}
				l=1;
				r=m;
				while(l<=r)
				{
					int mid=(l+r)/2;
					if(b[mid]>=y)
					{
						c[k].r=mid;
						r=mid-1;
					}
					else
						l=mid+1;
				}
				c[k].r--;
				if(c[k].r<c[k].l)
					k--;
			}
		}
		cout<<k<<" ";
		sort(c+1,c+k+1,cmp);
		for(i=1;i<=k;i++)
		{
			if(c[i].l>la)
			{
				la=c[i].r;
				ans--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
