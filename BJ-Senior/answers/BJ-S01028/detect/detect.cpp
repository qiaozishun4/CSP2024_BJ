#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int d[N],v[N],a[N],p[N];
int main(){
	int t,n,m,l,V;
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V && d[i]<=p[m]) cnt++;
			}else if(a[i]>0){
				if(d[i]<=p[m] && v[i]*v[i]+2*a[i]*(p[m]-d[i])>V*V ) cnt++;
			}
		}
		cout<<cnt<<" ";
		if(cnt!=0) cout<<m-1<<"\n";
		else cout<<m<<"\n";
	}
	return 0;
}
