#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <fstream>
#define lln long long
using namespace std;
const int N=1e5+2;
const int Len=1e6+2;
int T;
lln n,m,L,V;
lln ans,cnt;
lln mpos[N],scnt[Len];//pre suc sum of test device
lln dd[N],vd[N],ad[N],ed;//increase v
lln dm[N],vm[N],am[N],em;//decrease v
struct sgln
{
	int l,r;
}arr[N];
bool cmp(sgln a,sgln b)
{
	if(a.r==b.r)
	{
		return a.l<b.l;
	}
	else return a.r<b.r;
}
int pos;
lln cal(lln v0,lln a0,int tp)
{
	//V^2-v0^2=2ax
	lln tmp=V*V-v0*v0;
	if(tmp<0) tmp=(-1)*tmp;
	lln x=tmp/(2*a0);
	x+=tp*1;
	if(tp==0&&tmp%(2*a0)==0) x-=1;
	return x;
}
lln bs(lln k)
{
	int l=1,r=m;
	while(r-l>3)
	{
		int mid=(l+r)>>1;
		if(mpos[mid]<=k) l=mid;
		else r=mid-1; 
	}
	for(int i=r;i>=l;i--)
	{
		if(mpos[i]<=k) return mpos[i];
	}
	return 0;
}
void addln(int l,int r)
{
	++pos;
	arr[pos].l=l;
	arr[pos].r=r;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T)
	{
		ed=0;
		em=0;
		ans=0;
		cnt=0;
		pos=0;
		memset(scnt,0,sizeof(scnt));
		memset(mpos,0,sizeof(mpos));
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		lln di,vi,ai;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&di,&vi,&ai);
			if(ai>=0)//can reach L
			{
				++ed;
				dd[ed]=di;
				vd[ed]=vi;
				ad[ed]=ai;
			}
			else //may stop before L
			{
				++em;
				dm[em]=di;
				vm[em]=vi;
				am[em]=ai;
			}
		}
		for(int i=1;i<=m;i++) 
		{
			scanf("%lld",mpos+i);
			scnt[mpos[i]]+=1;
		}
		for(int i=1;i<=L;i++) //may start from 0
		{
			scnt[i]+=scnt[i-1];
		}
		//deal with increase speed
		//V^2=2ax,x->ceiling
		for(int i=1;i<=ed;i++)
		{
			lln xs=dd[i];
			if(vd[i]>V) 
			{
				if(xs==0) 
				{
					if(scnt[L]>0)
					{
						ans++;
						addln(xs,L);
					}
				}
				else 
				{
					if(scnt[L]-scnt[xs-1]>0)
					{
						ans++;
						addln(xs,L);
					}
				}
				continue;
			}
			//v0<V
			if(ad[i]==0)
			{
				continue;
			}
			lln xt=xs+cal(vd[i],ad[i],1);
			if(xt>L) continue;
			//xt>0
			if(scnt[L]-scnt[xt-1]>0) 
			{
				ans++;
				addln(xt,L);
			}
		}
		for(int i=1;i<=em;i++)
		{
			if(vm[i]<=V) continue;
			lln xs=dm[i];
			lln xt=xs+cal(vm[i],(-1)*am[i],0);//floor
			if(xt>L) xt=L;
			if(xs==0)
			{
				if(scnt[xt]>0) 
				{
					ans++;
					addln(xs,xt);
				}
			}
			else if(scnt[xt]-scnt[xs-1]>0)
			{
				ans++;
				addln(xs,xt);
			}
			//cout<<xs<<' '<<xt<<endl;
		}
		sort(arr+1,arr+1+pos,cmp);
		sort(mpos+1,mpos+1+m);
		lln cur=-1;
		//for(int i=1;i<=pos;i++) cout<<arr[i].l<<" "<<arr[i].r<<endl;
		//cout<<"*****"<<endl;
		for(int i=1;i<=pos;i++)
		{
			if(arr[i].l>cur)
			{
				//cout<<cur<<" "<<arr[i].l<<" "<<arr[i].r<<endl;
				lln fx=bs(arr[i].r);
				cur=fx;
				cnt++;
			}
		}
		printf("%lld %lld\n",ans,m-cnt);
		T-=1;
	}
	return 0;
}