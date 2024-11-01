#include<cstdio>
#include<algorithm>
#define TY int
#define MAXN 131072
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
using namespace std;
typedef long long ll;
const TY M=998244353;
typedef unsigned long long ull;
inline TY maxn(TY a,TY b){return a>b?a:b;}
inline TY minn(TY a,TY b){return a<b?a:b;}
inline TY _abs(TY a){return a<0?-a:a;}
inline void updmx(TY &a,TY b){if(a<b)a=b;}
inline void updmn(TY &a,TY b){if(a>b)a=b;}
TY qr(){
	TY x=1,s=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')x=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';return x*s;
}void qw(ll a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(ll a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar(a%10+'0');if(ch)putchar(ch);
}TY n,m,k,T,a[MAXN],b[MAXN],c[MAXN],x[4],id[18][MAXN];ll v;
ll sm[MAXN],ans;char s[18][MAXN];TY ar[MAXN],st[MAXN],L[18][MAXN],R[18][MAXN];
bool cmp(TY x,TY y){return c[x]<c[y];}
inline ll S(TY l,TY r){return 1ll*(r-l)*(l+r+1)>>1;}
void pre(TY x,TY u,TY l,TY r){
	if(l>r)return;TY mid=(u<<1|1)<<x-1,p,q;--mid;p=l;q=r;
	while(1){
		if(c[ar[p]]>=mid){
			L[x][u]=p-1;
			while(p<=r&&c[ar[p]]==mid)++p;
			R[x][u]=p;break;
		}if(c[ar[q]]<=mid){
			R[x][u]=q+1;
			while(c[ar[q]]==mid)--q;
			L[x][u]=q;break;
		}++p;--q;
	}pre(x-1,u<<1,l,L[x][u]);pre(x-1,u<<1|1,R[x][u],r);
}void findans(TY x,TY u,TY mn,TY l,TY r){
	if(l>r)return;
	TY mid=(u<<1|1)<<x-1;--mid;
//	qw(x,' ');qw(u,' ');qw(mn,' ');qw(mid,'\n');
	if(!u){
		findans(x-1,u<<1,mn,l,L[x][u]);
		sm[L[x][u]+1]+=id[x-1][u<<1]+1;
		sm[R[x][u]]-=id[x-1][u<<1]+1;l=R[x][u];
	}if(l>r)return;if(s[x][u]=='0'){
		TY ps=id[x-1][u<<1];
		if(a[ps]<x){
			v=S(mid+1,u+1<<x);
			if(L[x][u]+1>=l){
				sm[L[x][u]+1]+=v;
				sm[R[x][u]]-=v;
				fOR(i,L[x][u]+1,R[x][u])st[i]=-1;
			}findans(x-1,u<<1|1,mn,R[x][u],r);
		}else{
			if(a[ps]>=mn){
				sm[maxn(l,L[x][u]+1)]+=ps+1;
				sm[r+1]-=ps+1;
			}FOR(i,maxn(L[x][u]+1,l),r)st[i]=a[ps];
		}findans(x-1,u<<1,maxn(mn,x),l,L[x][u]);
		v=S(mid+1,u+1<<x);
		FOR(i,l,L[x][u])if(st[i]<x)
			{sm[i]+=v;sm[i+1]-=v;st[i]=-1;}
		return;
	}TY ps=id[x-1][u<<1];v=S(mid+1,u+1<<x);
	if(L[x][u]+1>=l){
		sm[l]+=v;sm[R[x][u]]-=v;
		if(a[ps]>=mn){
			sm[L[x][u]+1]+=ps+1;
			sm[R[x][u]]-=ps+1;
		}fOR(i,L[x][u]+1,R[x][u])st[i]=-1;
	}findans(x-1,u<<1,mn,l,L[x][u]);
	FOR(i,l,L[x][u])st[i]=-1;
	findans(x-1,u<<1|1,maxn(mn,x),R[x][u],r);
	ps=id[x-1][u<<1];
	FOR(i,R[x][u],r)if(st[i]<x){
		if(a[ps]>=mn){sm[i]+=ps+1;sm[i+1]-=ps+1;}
		if(st[i]!=-1)st[i]=a[ps];
	}
}int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=qr();m=qr();
	fOR(i,0,n)b[i]=qr();
	FOR(i,1,m)c[ar[i]=i]=qr()-1;
	sort(ar+1,ar+m+1,cmp);
	while((1<<k)<n)++k;pre(k,0,1,m);
	FOR(i,1,k)scanf("%s",s[i]);
	T=qr();while(T--){
		fOR(i,0,4)x[i]=qr();ans=0;
		fOR(i,0,n)a[i]=minn(k,b[i]^x[(i+1)&3]);
		fOR(i,0,1<<k)id[0][i]=i;
		FOR(i,1,k)fOR(j,0,1<<k-i){
			v=s[i][j]-'0';
			if(a[id[i-1][j<<1|v]]>=i)id[i][j]=id[i-1][j<<1|v];
			else id[i][j]=id[i-1][j<<1|(v^1)];
		}FOR(i,1,m)sm[i]=0;findans(k,0,0,1,m);
		FOR(i,1,m)sm[i]+=sm[i-1];
		FOR(i,1,m)ans^=(sm[i]*ar[i]);qw(ans,'\n');
	}return 0;
}