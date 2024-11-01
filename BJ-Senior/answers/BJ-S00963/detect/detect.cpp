#include<bits/stdc++.h>
#define int long long
#define I 1e18
using namespace std;
const int N=100005;
struct interval{int l,r;}q[N];
int cmp(interval x,interval y){return ((x.l!=y.l)?(x.l<y.l):(x.r<y.r));}
int _,n,m,L,V,d[N],v[N],a[N],p[N],cnt;
int check(int st,int ed,int s,int c){
	if(2*(ed-st)*c>V*V-s*s) return 1;
	return 0;
}
int ef1(int st,int s,int c,int lt){
	int rt=m,ans;
	while(lt<=rt){
		int mid=(lt+rt)>>1;
		if(check(st,p[mid],s,c)) rt=mid-1,ans=mid;
		else lt=mid+1;
	}
	return ans;
}
int ef2(int st,int s,int c,int lt){
	int rt=m,ans;
	while(lt<=rt){
		int mid=(lt+rt)>>1;
		if(check(st,p[mid],s,c)) lt=mid+1,ans=mid;
		else rt=mid-1;
	}
	return ans;
}
void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&L,&V),cnt=0;
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
	sort(p+1,p+m+1);
	for(int i=1;i<=n;i++){
		int st=lower_bound(p+1,p+m+1,d[i])-p;
		if(!a[i] && v[i]>V && st<=m) q[++cnt].l=st,q[cnt].r=m;
		else if(a[i]>0 && check(d[i],p[m],v[i],a[i]) && st<=m) q[++cnt].l=ef1(d[i],v[i],a[i],st),q[cnt].r=m;
		else if(a[i]<0 && check(d[i],p[st],v[i],a[i]) && st<=m) q[++cnt].l=st,q[cnt].r=ef2(d[i],v[i],a[i],st);
	}
	printf("%lld ",cnt);
	sort(q+1,q+cnt+1,cmp);
	int ans=1,mr=q[1].r;
	for(int i=2;i<=cnt;i++){
		if(q[i].l>mr) ans++,mr=q[i].r;
		else mr=min(mr,q[i].r);
	}
	if(!cnt) ans--;
	printf("%lld\n",m-ans);
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&_);
	while(_--) solve();
	return 0;
}
