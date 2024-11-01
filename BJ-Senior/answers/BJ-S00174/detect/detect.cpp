#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int T,n,m,L,V,p[100010],dp[100010];
bool is[100010];
struct Node{
	int d,v,a;
}c[100010];
struct G{
	int l,r;
}e[100010];
bool cmp(G _1,G _2) {
	return _1.r<_2.r||(_1.r==_2.r&&_1.l<_2.l);
}
signed main(void) {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (;T--;) {
		int tot=0;
		cin >> n >> m >> L >> V;
		for (int i=1;i<=n;i++) cin >> c[i].d >> c[i].v >> c[i].a;
		for (int i=1;i<=m;i++) cin >> p[i];
		sort(p+1,p+1+m);
		for (int i=1;i<=n;i++) is[i]=0;
		for (int i=1;i<=n;i++) {
			if (c[i].a<0) {
				int h=lower_bound(p+1,p+1+m,c[i].d)-p;
				if (h==m+1) continue;
				int s=p[h]-c[i].d;
				int delta=c[i].v*c[i].v+2*c[i].a*s;
				if (delta<0) continue;
				double g=sqrt(delta);
				if (g>V) is[i]=1;
			} else {
				if (c[i].d>p[m]) continue;
				int s=p[m]-c[i].d;
				int delta=c[i].v*c[i].v+2*c[i].a*s;
				if (delta<0) continue;
				double g=sqrt(delta);
				if (g>V) is[i]=1;
			}
		}
		int ans1=0;
		for (int i=1;i<=n;i++) ans1+=is[i];
		cout << ans1 << " ";
		for (int i=1;i<=n;i++) {
			if (!is[i]) continue;
			if (c[i].a>=0) {
				int h=lower_bound(p+1,p+1+m,c[i].d)-p-1;
				int l=h+1,r=m;
				if (l>r) continue;
				for (;l<=r;) {
					int mid=(l+r)>>1;
					if ((double)sqrt((c[i].v*c[i].v)+2*c[i].a*(p[mid]-c[i].d))>V) r=mid-1;
					else l=mid+1;
				}
				e[++tot]=G{l,n};
			} else {
				int h=lower_bound(p+1,p+1+m,c[i].d)-p-1;
				int l=h+1,r=m;
				if (l>r) continue;
				for (;r-l>=7;) {
					int mid=(l+r)>>1;
					int delta=c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d);
					if (delta<0) r=mid;
					else {
						if ((double)sqrt(delta)>V) l=mid;
						else r=mid;
					} 
				}
				int val=0;
				for (int j=l;j<=r+1;j++) {
					int delta=c[i].v*c[i].v+2*c[i].a*(p[j]-c[i].d);
					if (delta<0) {val=j-1;break;}
					if ((double)sqrt(delta)<=V) {val=j-1;break;}
				}
				if (val==0) val=n;
				e[++tot]=G{h+1,val};
			}
		}
		sort(e+1,e+1+tot,cmp);
		int px=0;
		int ll=0,rr=1e9;
		for (int i=1;i<=tot;i++) {
			if (rr>=e[i].l) {
				ll=max(ll,e[i].l);
				rr=min(rr,e[i].r);
			} else {
				px++;
				ll=e[i].l;
				rr=e[i].r;
			}
		}
		px++;
		cout << m-px << endl;
	}
	return 0;
}