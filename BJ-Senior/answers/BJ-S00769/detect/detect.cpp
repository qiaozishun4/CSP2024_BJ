#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+5,S=1e6+5;
int T,n,m,L,V,ans;
int d[N],v[N],a[N],p[N],s[S],cl[S];
struct node
{
	int st,en;
}c[N];
bool ch(int x,int y)
{
	if(x==0)
	{
		if(s[y]>0)	return true;
		return false;
	}
	else if(s[y]-s[x-1]>0)	return true;
	return false;
}
int cmp(node x,node y)
{
	return x.st<y.st;
}
void go()
{
	if(ans==0)
	{
		cout<<m;
		return ;
	}
	sort(c+1,c+ans+1,cmp);
	int res=0,cnt=1,la=L+1;
	for(int i=c[1].st;i<=L;i++)
	{
		if(c[cnt].st==i&&cl[la]<i)
		{
			res++;
			la=L+1;
		}
		while(c[cnt].st==i)
		{
			la=min(la,c[cnt].en);
			cnt++;
		}
	}
	if(la!=L+1)	res++;
	cout<<m-res;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		ans=0;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(s,0,sizeof(s));
		memset(c,0,sizeof(c));
		memset(cl,0,sizeof(cl));
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			s[p[i]]=1;
		}
		for(int i=1;i<=L+1;i++)
		{
			if(s[i]==1)	cl[i]=i;
			else cl[i]=cl[i-1];
			s[i]+=s[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]<=V)	continue;
				if(ch(d[i],L))
					c[++ans].st=d[i],c[ans].en=L;
			}
			else if(a[i]>0)
			{
				if(v[i]>V)
				{
					if(ch(d[i],L)) c[++ans].st=d[i],c[ans].en=L;
					continue;
				}
				int x=(V*V-v[i]*v[i])/(2*a[i])+1;
				if(x+d[i]>L)	continue;
				if(ch(x+d[i],L)) c[++ans].st=x+d[i],c[ans].en=L;
			}
			else
			{
				if(v[i]<=V)	continue;
				int x=(v[i]*v[i]-V*V)/(2*a[i]*(-1));
				if((v[i]*v[i]-V*V)%(2*a[i]*(-1))==0)	x--;
				int tmp=min(L,x+d[i]);
				if(ch(d[i],tmp)) c[++ans].st=d[i],c[ans].en=tmp;
			}
		}
		cout<<ans<<' ';
		go();
		cout<<endl;
	}
	return 0;
}
