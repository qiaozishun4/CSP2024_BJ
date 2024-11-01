#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define N 100007
int n,m,L,V,d[N],v[N],a[N],p[N];
struct qwq{int l,r;}x[N];
inline bool cmp(qwq a,qwq b){
	if(a.r!=b.r) return a.r>b.r;
	return a.l>b.l;
}

int k,Car;
inline void find(int i){
	if(d[i]>p[m]) return;
    if(!a[i]){
		if(v[i]<=V) return;
		int pp=lower_bound(p+1,p+m+1,d[i])-p;
		x[++k]={pp,m};Car++;return;
	}
	if(a[i]>0){
		LL vmax=v[i]*v[i]+2ll*a[i]*(p[m]-d[i]);
		if(vmax<=V*V) return;
		int L=lower_bound(p+1,p+m+1,d[i])-p,R=m;
        while(L<R){
            int mid=(L+R)>>1;
            vmax=v[i]*v[i]+2ll*a[i]*(p[mid]-d[i]);
            if(vmax>V*V) R=mid;
            else L=mid+1;
        }
        x[++k]={L,m};Car++;return;
    }
    if(a[i]<0){
        if(v[i]<=V) return;
        a[i]=-a[i];
        int L0=lower_bound(p+1,p+m+1,d[i])-p;
        int L=L0,R;
        if(!a[i]) return;
        int rmp=(v[i]*v[i])/(a[i]*2);
        LL E=d[i]+rmp;
        if(E<p[L]) return;
        a[0]++;
		a[i]=-a[i];
        int vv=v[i]*v[i]+2ll*a[i]*(p[L]-d[i]);
        if(vv<=V*V) return;
        
        if(E>=p[m]) R=m;
        else R=lower_bound(p+1,p+m+1,E)-p;
        while(L<R){
            //cout<<L<<' '<<R<<'\n';
            int mid=(L+R+1)>>1;
            vv=v[i]*v[i]+2ll*a[i]*(p[mid]-d[i]);
            //cout<<"pos="<<p[mid]<<",v="<<vv<<'\n';
            if(vv>V*V) L=mid;
            else R=mid-1;
        }
        x[++k]={L0,R};Car++;return;
    }
}

inline int solve(){
	k=Car=0;a[0]=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
	for(int i=1;i<=m;i++) cin>>p[i];
	
	for(int i=1;i<=n;i++) find(i);
	cout<<Car<<' ';
	if(!Car) {cout<<m<<'\n';return 0;}
	
	sort(x+1,x+k+1,cmp);
	
	//for(int i=1;i<=k;i++) cout<<x[i].l<<' '<<x[i].r<<'\n';
	
	int Ans=1,L=x[1].l,R=x[1].r;
    for(int i=2;i<=k;i++){
        if(x[i].l<=R&&L<=x[i].r){
            L=max(L,x[i].l),R=min(R,x[i].r);
        }
        else{
            Ans++,L=x[i].l,R=x[i].r;
        }
    }
    cout<<m-Ans<<'\n';
	
	return 0;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin>>T;
	while(T--) solve();

    return 0;
}
