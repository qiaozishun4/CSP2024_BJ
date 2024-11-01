#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,v,p[100005],ll,rr,mid,ansb,S,ans1,ans2,ks[100005],js[100005],t[1000005],j,vis[100005],maxk;
double ret;
struct car
{
	int d,v0,a;
}c[100005];
struct node
{
	bool sd;
	bool flag;
	int pos;
}cnt[100005],awa;
bool check1(int id,int x)
{
	S=p[id]-c[x].d;
	if(S<0) return false;
	ret=ceil(sqrt(c[x].v0*c[x].v0*1.0+2.0*c[x].a*S));
	if((int)(ret)>v) return true;
	return false;
}
node b_search1(int x)
{
	ll=1,rr=m,ansb=-1;
	while(ll<=rr)
	{
		mid=ll+rr>>1;
		if(check1(mid,x)) ansb=mid,rr=mid-1;
		else ll=mid+1;
	}
	if(ansb<0) awa.sd=0,awa.flag=0,awa.pos=0;
	else awa.sd=0,awa.flag=1,awa.pos=ansb;
	return awa;
}
bool check2(int id,int x)
{
	S=p[id]-c[x].d;
	if(S<0||c[x].v0*c[x].v0+c[x].a*S<0) return false;
	ret=ceil(sqrt(c[x].v0*c[x].v0*1.0+2.0*c[x].a*S));
	if((int)(ret)>v) return true;
	return false;
}
node b_search2(int x)
{
	ll=1,rr=m,ansb=-1;
	while(ll<=rr)
	{
		mid=ll+rr>>1;
		if(check2(mid,x)) ansb=mid,ll=mid+1;
		else if(p[mid]<c[x].d) ll=mid+1;
		else rr=mid-1;
	}
	if(ansb<0) awa.sd=1,awa.flag=0,awa.pos=0;
	else awa.sd=1,awa.flag=1,awa.pos=ansb;
	return awa;
}
bool f_check(int x)
{
	for(int i=ks[x];i<=js[x];i++) if(vis[j]) return false;
	return true;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		maxk=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&c[i].d,&c[i].v0,&c[i].a);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]),vis[i]=0;
		ans1=0,ans2=0;
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)
		{
			if(c[i].a>=0) cnt[i]=b_search1(i);
			else cnt[i]=b_search2(i);
			if(c[i].a>=0&&cnt[i].flag) ks[i]=cnt[i].pos,js[i]=m;
			else if(c[i].a<0&&cnt[i].flag) js[i]=cnt[i].pos;
		}
		for(int i=1;i<=n;i++) if(cnt[i].flag) ans1++;
		printf("%d ",ans1);
		j=1;
		for(int i=1;i<=l;i++)
		{
			if(i>p[j]) j++;
			t[i]=j;
		}
		for(int i=1;i<=n;i++) if(cnt[i].flag&&c[i].a<0) ks[i]=t[c[i].d];
		for(int i=1;i<=n;i++)
		{
			if(cnt[i].flag)
			{
				for(int j=ks[i];j<=js[i];j++)
				{
					vis[j]++;
					maxk=max(maxk,vis[j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]!=vis[i-1]&&vis[i]==maxk) ans2++;
		}
		printf("%d\n",m-ans2);
	}
	return 0;
}
