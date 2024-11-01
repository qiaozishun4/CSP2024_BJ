#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int maxn = 1e5+5;
int d[maxn],v[maxn],a[maxn],p[maxn],utop;
int n,m;
struct un{
	int l, r;
}u[maxn];
bool cmp(un a,un b){
	if(a.l<b.l)
		return true;
	if(a.r<b.r)
		return true;
	return false;
}
int cal(){
	int res=1;
	int ll = u[1].l,rr = u[1].r;
	for(int i=2;i<=utop;i++){
		if(u[i].l>rr){
			res++;
			ll = u[i].l,rr = u[i].r;
		}
		rr = min(u[i].r,rr);
	}
	return res;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		memset(u,0,sizeof(u));
		utop = 0;
		int L,V,ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++)
			scanf("%lld",&p[i]);
		sort(p+1,p+1+m);
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V&&d[i]<=p[m]){
					ans++;
					int idxl = lower_bound(p+1,p+m,d[i])-p;
					u[++utop].l = idxl,u[utop].r = m;
				}
			}
			else if(a[i]>0){
				int f = V*V-v[i]*v[i];
				double a0 = a[i],d0=d[i];
				double s = f/(2*a0)+d0,p0 = p[m];
				if(s<=p0){
					ans++;
					int idxl = upper_bound(p+1,p+m,s)-p;
					u[++utop].l = idxl,u[utop].r = m;
				}
			}
			else{
				if(v[i]>V){
					int f = V*V-v[i]*v[i];
					double a0 = a[i],d0 = d[i];
					double s = f/(2*a0)+d0;
					int idxl = lower_bound(p+1,p+m,d[i])-p;
					double p0 = p[idxl];
					if(s>p0){
						ans++;
						int idxr = lower_bound(p+1,p+m,s)-p-1;
						u[++utop].l = idxl,u[utop].r = idxr;
					}
				}
			}
		}
		sort(u+1,u+utop+1,cmp);
		if(ans==0) printf("%lld %lld\n",ans,m);
		else printf("%lld %lld\n",ans,(m-cal()));
	}
	return 0;
}