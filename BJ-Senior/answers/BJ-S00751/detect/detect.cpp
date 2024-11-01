#include<bits/stdc++.h>
using namespace std;
const double SM=0.0000001;
const int N=1e5+7;
int t,n,m,tot,ans;
double L,V,p[N];
bool marked[N];
struct car {double l,v,a;}c[N];
struct overspeed_segment {
	int l,r;
	bool operator<(const overspeed_segment S) const {
		return r<S.r;
}	}o[N];
struct sortseg {
	int l,pos;
	bool operator<(const sortseg S) const {
		return l>S.l;
}	}s[N],tmp;
priority_queue<sortseg> q;
int l,r,mid;
inline int get_p(double D) {
	p[m+1]=DBL_MAX;
	l=1,r=m+1;
	while(l<r)
		mid=l+r>>1,
		p[mid]>=D?r=mid:l=mid+1;
	return l;
}
inline void get_overspeed_segment(car key) {
	if(key.v>V)
	{
		if(key.a>=0.0)
		{
			o[++tot].l=get_p(key.l);
			o[tot].r=m;
			if(o[tot].l>m) tot--;
		}
		else if(key.a<0.0)
		{
			key.a=-key.a;
			o[++tot].l=get_p(key.l);
			o[tot].r=get_p(key.l+(key.v*key.v-V*V)/(key.a*2.0))-1;
			if(o[tot].r<o[tot].l) tot--;
	}	}
	else if(key.a>0.0)
	{
		 o[++tot].l=get_p(key.l+(V*V-key.v*key.v)/(key.a*2.0)+SM);
		 o[tot].r=m;
		 if(o[tot].r<o[tot].l) tot--;
	}
	return ;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	for(scanf("%d",&t);t;t--)
	{
		tot=ans=0;
		while(!q.empty()) q.pop();
		scanf("%d%d%lf%lf",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf",&c[i].l,&c[i].v,&c[i].a);
		for(int i=1;i<=m;i++)
			scanf("%lf",&p[i]);
		for(int i=1;i<=n;i++)
			get_overspeed_segment(c[i]);
		sort(o+1,o+tot+1);
		for(int i=1;i<=tot;i++) 
			marked[i]=0;
		for(int i=1;i<=tot;i++)
			tmp.l=o[i].l,tmp.pos=i,q.push(tmp);
		printf("%d ",tot);
		for(int i=1;i<=tot;i++)
			if(!marked[i])
			{
				ans++,marked[i]=1;
				while(!q.empty()&&q.top().l<=o[i].r)
					marked[q.top().pos]=1,q.pop();
			}
		printf("%d\n",m-ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}