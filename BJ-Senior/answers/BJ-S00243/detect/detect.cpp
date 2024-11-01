#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int q,n,m,s;//..?
double l,p[N],d[N],v[N],a[N];
double x[N],y[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> q;
	while(q--){
		cin >> n >> m >> l >> s;
		for(int i=1;i<=n;i++) cin >> d[i] >> v[i] >> a[i];
		for(int i=1;i<=m;i++) cin >> p[i];
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>s) cnt++;
				continue;
			}
			double t=(s-v[i])/a[i];
			double dis=v[i]*t+0.5*a[i]*t*t+d[i];
			if(a[i]<0) x[i]=d[i],y[i]=min(dis,l);
			if(a[i]>=0) x[i]=dis,y[i]=l;
			bool flag=false;
			for(int j=1;j<=m;j++){
				if(x[i]<=p[j] && p[j]<=y[i]){
					cnt++;
					break;
				}
			}
		}
		cout << cnt << " " <<  m << endl;
	}
	return 0;
}