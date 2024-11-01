#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int k,t,n,m,f,x[4],a[N],b[N],c[N],d[N],ans[N],op;
int tot,lst[N<<2],nxt[N<<2];
inline int rdm(int x,int y) {return b[(1<<k+1)-(1<<k-x+2)+y];}
struct seg {int l,r,head;}s[N<<2];
inline void add_l(int h,int val) {lst[++tot]=val,nxt[tot]=h,h=tot;return ;}
inline void cmb(int R,int g,int node,int l,int r) {
	if(l==r-1)
	{
		if(rdm(R,g)) add_l(s[node].head,(a[r]>=R?r:l));
		else add_l(s[node].head,(a[l]>=R?l:r));
		return ;
	}
	int lc=node<<1,rc=(node<<1)+1;
	cmb(R-1,g<<1,lc,l,l+r>>1);
	cmb(R-1,(g<<1)+1,rc,(l+r>>1)+1,r);
	if(rdm(R,g))
	{
		int cnt=0,tmp=0;
		for(int i=s[rc].head,key;i;i=nxt[i])
		{
			cnt++;
			key=lst[i];
			if(a[key]>=R) tmp++,add_l(s[node].head,key);
		}
		if(tmp!=cnt) for(int i=s[lc].head,key;i;i=nxt[i])
			add_l(s[node].head,lst[i]);
	}
	else 
	{
		int cnt=0,tmp=0;
		for(int i=s[lc].head,key;i;i=nxt[i])
		{
			cnt++;
			key=lst[i];
			if(a[key]>=R) tmp++,add_l(s[node].head,key);
		}
		if(tmp!=cnt) for(int i=s[rc].head,key;i;i=nxt[i])
			add_l(s[node].head,lst[i]);
	}
	if(l==1) 
	{
		ans[r]=0;
		for(int i=s[node].head;i;i=nxt[i])
			ans[r]+=lst[i];
	}
	return ;
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	for(cin>>t;t;t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&c[i]);
		k=0;
		while((1<<k)<n) k++;
		for(int i=1;i<=(1<<k+1)-1;i++)
			scanf("%d",&b[i]);
		for(scanf("%d",&t);t;t--)
		{
			scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
			for(int i=1;i<=n;i++)
				a[i]^=x[i%4];
			cmb(k,1,1,1,1<<k);
			op=ans[c[1]];
			for(int i=2;i<=m;i++)
				op^=ans[c[i]];
			printf("%d\n",op);
		}
	}
	fclose(stdin);
	fclose(stdout);
}