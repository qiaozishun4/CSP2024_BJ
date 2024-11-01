#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e5;
int T,n,m,len,V,mon[N+1]={-1},p,ans1,ans2;
struct node
{
	int d,v,a;
}c[N+1];
struct ext
{
	int l,r;
	bool operator < (const ext &a)const
	{
		if(r<a.r)
			return 1;
		if(r==a.r && l<a.l)
			return 1;
		return 0;
	}
}e[N+1];
int bin(int l,int r,int key)
{
	int mid;
	while(l<r-1)
	{
		mid=l+(r-l>>1);
		if(mon[mid]>key)
			r=mid-1;
		else
			l=mid;
	}
	if(mon[r]<=key)
		return r;
	return l;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int i,q,x;
	cin>>T;
	while(T--)
	{
		p=0;
		ans1=0;
		ans2=0;
		cin>>n>>m>>len>>V;
		for(i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(i=1;i<=m;i++)
			cin>>mon[i];
		for(i=1;i<=n;i++)
		{
			if(c[i].a>0)
			{
				if(c[i].v>V)
				{
					e[++p].l=c[i].d;
					e[p].r=len;
				}
				else
				{
					x=floor(((V*V-c[i].v*c[i].v)/2.0)/c[i].a+1);
					if(c[i].d+x<=len)
					{
						e[++p].l=c[i].d+x;
						e[p].r=len;
					}
				}
			}
			else if(c[i].a==0)
			{
				if(c[i].v>V)
				{
					e[++p].l=c[i].d;
					e[p].r=len;
				}
			}
			else
				if(c[i].v>V)
				{
					x=ceil(((V*V-c[i].v*c[i].v)/2.0)/c[i].a-1);
					e[++p].l=c[i].d;
					e[p].r=min(c[i].d+x,len);
				}
		}
		sort(e+1,e+p+1);
		
		/*cout<<endl;
		for(i=1;i<=p;i++)
			cout<<e[i].l<<','<<e[i].r<<endl;
		cout<<endl;*/
		
		q=0;
		for(i=1;i<=p;i++)
		{
			if(e[i].l<=mon[q] && e[i].r>=mon[q])
			{
			
				//cout<<i<<' '<<q<<endl;
			
				ans1++;
				continue;
			}
			else
			{
				x=bin(1,m,e[i].r);
				if(mon[x]<=e[i].r && mon[x]>=e[i].l)
				{
					//cout<<i<<' '<<q<<"->"<<x<<endl;
					
					ans1++;
					ans2++;
					q=x;
				}
			}
		}
		cout<<ans1<<' '<<m-ans2<<endl;
	}
	return 0;
}