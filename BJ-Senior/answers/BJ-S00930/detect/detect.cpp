#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=100000+5;
int p[M];
bool kip[M];
struct car{
	int d,v,a;
}c[M];
struct Range{
	int l,r;
	bool operator < (const Range&x) const{
		return r<x.r;
	}
}range[M]; int cntr=0;
int findp(int d,int m){
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)/2;
		if(d>p[mid]){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return l;
}
void solve(){
	int ans=0,cntr=0;
	
	int n,m,L,V;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		cin>>c[i].d>>c[i].v>>c[i].a;
	}
	for(int i=1;i<=m;i++) cin>>p[i];
	for(int i=1;i<=m;i++) kip[i]=0;
	
	for(int i=1;i<=n;i++){
		int d=c[i].d,v=c[i].v,a=c[i].a;
		if(a>=0){//p[m]
			int s=p[m]-d;
			if(v*v+2*a*s>V*V && s>=0){
				++ans;//kip[m]=1;
				int l=findp(d,m), r=m;
				while(l<r){
					int mid=(l+r)/2;
					s=p[mid]-d;
					if(v*v+2*a*s>V*V){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				//append l,m;
				++cntr;
				range[cntr].l=l;
				range[cntr].r=m;
				//cout<<i<<' '<<range[cntr].l<<' '<<range[cntr].r<<endl;
			}
		}
		else{
			int k=findp(d,m);
			int s=p[k]-d;
			if(v*v+2*a*s>V*V && s>=0){
				++ans;//kip[k]=1;
				int l=k, r=m+1;
				while(l<r){
					int mid=(l+r)/2;
					s=p[mid]-d;
					if(v*v+2*a*s<=V*V){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				++cntr;
				range[cntr].l=k;
				range[cntr].r=l-1;
				//cout<<i<<' '<<range[cntr].l<<' '<<range[cntr].r<<endl;
			}
		}
	}
	cout<<ans<<" ";
	//cout<<endl;
	sort(range+1,range+cntr+1);
	int cnt2=m;
	int lst=0;
	for(int i=1;i<=cntr;i++){
		//cout<<range[i].l<<' '<<range[i].r<<endl;
		if(range[i].l>lst){
			lst=range[i].r;
			--cnt2;
		}
	}
	cout<<cnt2<<endl;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
