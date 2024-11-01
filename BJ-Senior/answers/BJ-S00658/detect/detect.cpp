#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+7;
struct car{
	int d,v,a;
}a[maxn];
int n,m,L,V,ans=0,ans1=0;
int p[maxn];
int moreV(int l){
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(j==l) continue;
			if(a[i].d>p[j]) continue;
			int weiyi=p[j]-a[i].d;
			if(a[i].v*a[i].v+2*a[i].a*weiyi<=0) break;
			double shunV=sqrt(a[i].v*a[i].v+2*a[i].a*weiyi);
			if(shunV>V) {sum++;break;}
		}
	return sum;
}
void solve(){
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].a;
	for(int i=1;i<=m;i++) cin>>p[i];
	ans=moreV(0);
	//第l个测速仪关掉
	for(int l=1;l<=m;l++) if(moreV(l)==n) ans1++;
	cout<<ans<<' '<<ans1<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
