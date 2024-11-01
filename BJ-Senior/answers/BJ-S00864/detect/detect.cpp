#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f3f3f3f3f;
int n,d[N],v[N],a[N],m,p[N],V,L,minn,cnt=0,t;
struct js
{
	int f,e,no;
}c[N];
double s;
bool cmp(js kk,js ws)
{
	if(kk.f==ws.f) return kk.e<ws.e;
	return kk.f<ws.f;
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	for(cin>>t;t;--t)
	{
		memset(c,0x3f,sizeof c);
		cnt=0,minn=0;
		bool book=1;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;c[i].no=i,++i)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;++i) cin>>p[i];
		for(int i=1;i<=n;++i)
		{
			if(a[i]==0)
			{
				if(v[i]>V)
				{
					cnt++;
					int l=1,r=m,mid,ans=0;
					while(l<=r)
					{
						mid=(l+r)>>1;
						if(p[mid]>=d[i])
						{
							ans=mid;
							r=mid-1;
						}
						else
						{
							l=mid+1;
						}
					}
					if(ans)
					{
						c[i].f=ans;
						c[i].e=m;
					}
				}
			}
			else if(a[i]>0)
			{
				if(v[i]>V)
				{
					cnt++;
					int l=1,r=m,mid,ans=0;
					while(l<=r)
					{
						mid=(l+r)>>1;
						if(p[mid]>=d[i])
						{
							ans=mid;
							r=mid-1;
						}
						else
						{
							l=mid+1;
						}
					}
					if(ans)
					{
						c[i].f=ans;
						c[i].e=m;
					}
				}
				else
				{
					s=(V*V-v[i]*v[i])*1.0/2/a[i]+d[i];
					if(s>L) continue;
					cnt++;
					int l=1,r=m,mid,ans=0;
					while(l<=r)
					{
						mid=(l+r)>>1;
						if(p[mid]>=d[i])
						{
							ans=mid;
							r=mid-1;
						}
						else
						{
							l=mid+1;
						}
					}
					if(ans)
					{
						c[i].f=ans;
						c[i].e=m;
					}
				}
			}
			else
			{
				if(v[i]>V)
				{
					book=0;
					cnt++;
					int l=1,r=m,mid,ans=0;
					while(l<=r)
					{
						mid=(l+r)>>1;
						if(p[mid]>=d[i])
						{
							ans=mid;
							r=mid-1;
						}
						else
						{
							l=mid+1;
						}
					}
					s=(V*V-v[i]*v[i])*1.0/2/a[i]+d[i];
					if(ans&&s>=p[ans])
					{
						c[i].f=ans;
					}
					else
					{
						cnt--;
						continue;
					}
					l=1,r=m,mid,ans=0;
					while(l<=r)
					{
						mid=(l+r)>>1;
						if(p[mid]<=s)
						{
							ans=mid;
							l=mid+1;
						}
						else
						{
							r=mid-1;
						}
					}
					c[i].e=ans;
				}
			}
		}
		sort(c+1,c+n+1,cmp);
		cout<<cnt<<' ';
		cnt=0;
		if(book)
		{
			cout<<m-1<<endl;
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			if(c[i].f==inf) break;
			if(c[i].f<=minn)
			{
				minn=min(minn,c[i].e);
			}
			else
			{
				cnt++;
				minn=c[i].e;
			}
		}
		cout<<n-cnt<<endl;
	}
	return 0;
}