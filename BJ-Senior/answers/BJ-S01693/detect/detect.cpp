#include<cstdio>
#include<algorithm>
#define TY int
#define MAXN 100002
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
}void qw(TY a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(TY a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar(a%10+'0');
	if(ch)putchar(ch);
}TY T,n,m,L,V,d,v,a,l[MAXN],r[MAXN],p[MAXN],id[MAXN],ans,ct;
bool cmp(TY x,TY y){return r[x]<r[y];}
TY find1(TY v,TY a){
	if(v>V)return 0;
	return (V+v)*(V-v)/(a<<1)+1;
}TY find2(TY v,TY a){
	if(v<=V)return -1;
	return ((V+v)*(v-V)-1)/((-a)<<1);
}int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=qr();while(T--){
		n=qr();m=qr();L=qr();V=qr();
		ans=ct=0;FOR(i,1,n){
			id[i]=i;
			d=qr();v=qr();a=qr();
			if(a==0){
				if(v>V){l[i]=d;r[i]=L;}
				else{l[i]=1;r[i]=0;}continue;
			}if(a>0){l[i]=d+find1(v,a);r[i]=L;}
			else{l[i]=d;r[i]=d+find2(v,a);}
		}FOR(i,1,m)p[i]=qr();
		FOR(i,1,n){
			l[i]=lower_bound(p+1,p+m+1,l[i])-p;
			r[i]=upper_bound(p+1,p+m+1,r[i])-p-1;
			if(l[i]<=r[i])++ans;else l[i]=r[i]=m+1;
		}sort(id+1,id+n+1,cmp);
		a=0;FOR(i,1,ans)if(a<l[id[i]]){a=r[id[i]];++ct;}
		qw(ans,' ');qw(m-ct,'\n');
	}return 0;
}