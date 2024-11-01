#include<cstdio>
#define TY ll
#define MAXN 200002
#define MAXM 1000002
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
using namespace std;
typedef long long ll;
const TY M=998244353,INF=1e12;
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
}void qw(TY a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(TY a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar(a%10+'0');
	if(ch)putchar(ch);
}TY T,n,a[MAXN],dp[MAXM],mx,tag,tmp,ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=qr();while(T--){
		n=qr();ans=dp[0]=mx=tag=0;
		fOR(i,1,MAXM)dp[i]=-INF;
		FOR(i,1,n)a[i]=qr();
		FOR(i,2,n){
			tmp=maxn(mx,dp[a[i]]+tag+a[i]);
			if(a[i]==a[i-1]){mx+=a[i];tag+=a[i];}
			updmx(dp[a[i-1]],tmp-tag);updmx(mx,tmp);
		}fOR(i,0,MAXM)updmx(ans,dp[i]);qw(ans+tag,'\n');
	}return 0;
}