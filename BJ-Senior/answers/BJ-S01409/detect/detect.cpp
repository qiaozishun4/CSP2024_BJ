#include <bits/stdc++.h>
#define N 100010
using namespace std;
int T;
int n,m,l,V;
int d[N],v[N],a[N],c[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>c[i];
		if(a[1]==0){
			int far=0,ans=0;
			for(int i=1;i<=m;i++){
				far=max(far,c[i]);
			}
			for(int i=1;i<=n;i++){
				if(d[i]<=far&&v[i]>V) ans++;
			}
			cout<<ans<<' ';
			if(ans==0) cout<<m<<endl;
			else cout<<m-1<<endl;
		}
		else if(a[1]>0){
			int far=0,ans=0;
			for(int i=1;i<=m;i++){
				far=max(far,c[i]);
			}
			double vt;
			for(int i=1;i<=n;i++){
				vt=sqrt(2*a[i]*(far-d[i])+(v[i]*v[i]));
				if(d[i]<=far&&vt>V) ans++;
			}
			cout<<ans<<' ';
			if(ans==0) cout<<m<<endl;
			else cout<<m-1<<endl;
		}
	}
	return 0;
}
