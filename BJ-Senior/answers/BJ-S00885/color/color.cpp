#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define LL long long

template<class T>
inline void read(T &x){
    T f=-1;x=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    x*=f;
}

const int N=2e5+5;
int T,n,a[N];
inline int calc(int x,int y){return (x==y?x:0);}

namespace sub1{
	const int NF=2e3+5;
	int f[NF][NF][2],mx[2];
	inline void dp(){
		memset(f,-0x3f,sizeof(f));
		f[1][0][0]=f[1][0][1]=0;
		rep(i,2,n){
			mx[0]=mx[1]=-0x3f3f3f3f;
			rep(j,0,i-2) rep(o,0,1)
				f[i][j][o]=max(f[i][j][o],f[i-1][j][o]+calc(a[i],a[i-1])),
				mx[o]=max(mx[o],f[i-1][j][o]+calc(a[i],a[j]));
			rep(o,0,1) f[i][i-1][o]=max(f[i][i-1][o],mx[o^1]);
		}
	}
	inline void solve(){
		dp();
		int mx=0;
		rep(j,0,n-1) rep(o,0,1) mx=max(mx,f[n][j][o]);
		printf("%d\n",mx);
	}
}

namespace sub2{
	int f[N][11][2],mx[2];
	inline void dp(){
		memset(f,-0x3f,sizeof(f));
		f[1][0][0]=f[1][0][1]=0;
		rep(i,2,n){
			mx[0]=mx[1]=-0x3f3f3f3f;
			rep(j,0,10) rep(o,0,1)
				f[i][j][o]=max(f[i][j][o],f[i-1][j][o]+calc(a[i],a[i-1])),
				mx[o]=max(mx[o],f[i-1][j][o]+calc(a[i],j));
			rep(o,0,1) f[i][a[i-1]][o]=max(f[i][a[i-1]][o],mx[o^1]);
		}
	}
	inline void solve(){
		dp();
		int mx=0;
		rep(j,0,10) rep(o,0,1) mx=max(mx,f[n][j][o]);
		printf("%d\n",mx);
	}
}

namespace sub3{
	
	const int NF=2e4+5;
	LL f[2][NF];
	int c[NF],lim;
	inline int ccalc(int x,int y){return (x==y?c[x]:0);}
	inline void init(){
		rep(i,1,n) c[i]=a[i];
		sort(c+1,c+n+1);
		lim=unique(c+1,c+n+1)-c;
		rep(i,1,n) a[i]=lower_bound(c+1,c+lim+1,a[i])-c;
	}
	inline void dp(){
		memset(f,-0x3f,sizeof(f));
		f[1][0]=0;LL mx=0;
		rep(i,2,n){
			mx=-0x3f3f3f3f3f3f3f3f;
			rep(j,0,lim)
				f[i&1][j]=f[(i-1)&1][j]+ccalc(a[i],a[i-1]),
				mx=max(mx,f[(i-1)&1][j]+ccalc(a[i],j));
			f[i&1][a[i-1]]=max(f[i&1][a[i-1]],mx);
		}
	}
	inline void solve(){
		init();dp();
		LL mx=0;
		rep(j,0,lim) mx=max(mx,f[n&1][j]);
		printf("%lld\n",mx);
	}
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		if(n<=2000) {sub1::solve();continue;}
		int mx=0;
		rep(i,1,n) mx=max(mx,a[i]);
		if(mx<=10) {sub2::solve();continue;}
		if(n<=20000){sub3::solve();continue;}
	}
    return 0;
}