#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
ll t,n,m,l,v,x[100005],y[100005],p[100005],cnt;
struct _
{
	ll l,r;
	bool operator<(_ ot)
	{
		return l<ot.l;
	}
}s[100005];
void chk(ll a)
{
	ll r1=-1,r2=-1,l,r;
	l=1,r=m;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (p[mid]>=x[a])
		{
			r1=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	l=1,r=m;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (p[mid]<=y[a])
		{
			r2=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if (r2>=r1&&r1!=-1&&r2!=-1)
	{
		cnt++;
		s[cnt].l=r1;
		s[cnt].r=r2;
	}
}
int main()
{
	faster;
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n>>m>>l>>v;
		cnt=0;
		for (ll i=1;i<=n;i++)
		{
			ll d,v0,a;
			cin>>d>>v0>>a;
			if (a==0)
			{
				if (v0>v)x[i]=d,y[i]=l;
				else x[i]=y[i]=0;
			}
			else if (a<0)
			{
				if (v0<=v)x[i]=y[i]=0;
				else 
				{
					x[i]=d;
					double __=d+1.0*(v*v-v0*v0)/(2*a);
					if (__-floor(__)<=0.00000001)y[i]=min(l,(ll)floor(__-1));
					else y[i]=min(l,(ll)__);
				}
			}
			else
			{
				if (v0>v)x[i]=d,y[i]=l;
				else
				{
					y[i]=l;
					double __=d+(0.0+v*v-v0*v0)/(2*a);
					if (__-floor(__)<=0.00000001)x[i]=__+1;
					else x[i]=ceil(__);
					if (x[i]>l)x[i]=y[i]=0;
				}
			}
		}
		for (ll i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		sort(p+1,p+1+m);p[0]=-1;p[m+1]=p[m]+1;
		for (ll i=1;i<=n;i++)
		{
			chk(i);
		}
		cout<<cnt<<" ";
		ll ans=0,mn=LLONG_MAX;
		sort(s+1,s+1+cnt);
		for (ll i=1;i<=cnt;i++)
		{
			if (s[i].l>mn)
			{
				ans++;
				mn=LLONG_MAX;
			}
			mn=min(mn,s[i].r);
		}
		if (cnt!=0)cout<<m-ans-1<<"\n";
		else cout<<m<<"\n";
	}
	return 0;
}//60
