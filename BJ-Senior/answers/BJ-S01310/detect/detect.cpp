#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int T,n,m,L,V,d[N],v[N],a[N],p[N],q[N];
void solve(){
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)
		cin>>d[i]>>v[i]>>a[i];
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1;i<=m;i++)q[i]=m+1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int L=lower_bound(p+1,p+m+1,d[i])-p,R=m+1;
		if(a[i]>0){
			if(V<v[i]){
				R=L;
			}else{
				double t=1.0*(double)(V-v[i])/(double)a[i];
				double s=(double)v[i]*t+0.5*(double)a[i]*t*t;
				R=upper_bound(p+1,p+m+1,(double)d[i]+s)-p;
			}
			if(R<=m)cnt++;
			//else cout<<"s: "<<s<<" "<<d[i]+s<<"\n";
			q[R]=min(q[R],m);
		}else if(a[i]<0){
			double t=1.0*(double)(V-v[i])/(double)a[i];
			double s=(double)v[i]*t+0.5*(double)a[i]*t*t;
			//cout<<"s: "<<s<<" "<<t<<endl;
			if(V<v[i]){
				R=lower_bound(p+1,p+m+1,(double)d[i]+s)-p-1;
				if(L<=R)q[L]=min(q[L],R),cnt++;
			}
		}else{
			if(L<=m&&v[i]>V)q[L]=min(q[L],m),cnt++;
		}
		//cout<<"111: "<<L<<" "<<R<<"\n";
		//cout<<cnt<<"\n";
	}
	int now=m+1,ans=0;
	for(int i=1;i<=m;i++){
		now=min(now,q[i]);
		if(now==i){
			ans++;
			now=m+1;
		}
	}
	cout<<cnt<<" "<<m-ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}