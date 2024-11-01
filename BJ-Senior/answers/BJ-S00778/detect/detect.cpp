#include<bits/stdc++.h>
using namespace std;
bool book[100010];
int n,m,V,L,ans1,ans2,top,t,l,r,mid,ct[100010],E,tct;
long long tmp;
struct s2
{
	int l,r;
}edge[100010];
bool cmp(s2 a,s2 b)
{
	if(a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}
struct cars
{
	int v,a,d;
}p[100010];
bool check(int d,int i)
{
	tmp=p[i].v*p[i].v+2*p[i].a*(d-p[i].d);
	if(tmp>V*V) return true;
	return false;
}
int findl(int i)
{
	l=1,r=m;
	while(l<r)
	{
		mid=l+r>>1;
		if(ct[mid]<p[i].d) l=mid+1;
		else if(check(ct[mid],i)) r=mid;
		else l=mid+1;
	}
	return r;
}
int findp(int i)
{
	l=1,r=m;
	while(l<r)
	{
		mid=l+r>>1;
		if(ct[mid]<p[i].d) l=mid+1;
		else r=mid;
	}
	return l;
}
int findr(int i)
{
	l=1,r=m;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(ct[mid]<p[i].d) l=mid+1;
		else if(check(ct[mid],i)) l=mid;
		else r=mid-1;
	}
	return l;
}
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		if(p[i].a<=0)
		{
			tct=ct[findp(i)];
			if(tct<p[i].d) continue;
			tmp=p[i].v*p[i].v+2*p[i].a*(tct-p[i].d);
			if(tmp>V*V)
			{
				ans1++;
				book[i]=1;
			}
		}  
		
		else
		{
			tmp=p[i].v*p[i].v+2*p[i].a*(ct[m]-p[i].d);
			if(ct[m]<p[i].d) continue;
			if(tmp>V*V) 
			{
				ans1++;
				book[i]=1;
			}
		}
		//if(book[i]) cout<< i<<" ";
	}
	printf("%d ",ans1);
}


void solve2()
{
	top=1;
	for(int i=1;i<=n;i++)
	{
		if(book[i])
		{
			if(p[i].a>=0)
			{
				edge[top].l=findl(i);
				edge[top++].r=m;
			}
			else
			{
				edge[top].l=findp(i);
				edge[top++].r=findr(i);
			}
		}
		
	}
	sort(edge+1,edge+top,cmp);
	E=edge[1].r;
	ans2=1;
	for(int i=2;i<top;i++)
	{
		if(edge[i].l>E)
		{
			ans2++;
			E=edge[i].r;
		}
	}
	if(ans1==0) ans2--;
	printf("%d\n",m-ans2);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans1=ans2=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&p[i].d,&p[i].v,&p[i].a);
		for(int j=1;j<=m;j++) scanf("%d",&ct[j]);
		solve1();
		solve2();
		for(int i=1;i<=n;i++) book[i]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}