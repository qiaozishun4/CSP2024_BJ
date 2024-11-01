#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[100005],v[100005],a[100005],p[100005],as1,as2,mn,mx;
void sv(){
	as1=as2=mx=0;
	mn=1e9;
	cin >> n >> m >> L >> V;
	for(int i=1;i<=n;i++){
		cin >> d[i] >> v[i] >> a[i];
	}
	for(int i=1;i<=m;i++){
		cin >> p[i];
		mn=min(mn,p[i]);
		mx=max(mx,p[i]);
	}
	sort(p+1,p+1+m);
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if((v[i]>V&&d[i]<=mx)||((-v[i])>V&&d[i]<=mx)){
				as1++;
			}
			continue;
		}
		double xx=1.0*(V-v[i])/(1.0*a[i]);
		double yy=0.5*a[i]*xx*xx+1.0*v[i]*xx;
		yy=yy+1.0*d[i];
		if(a[i]<0){
			for(int j=1;j<=m;j++){
				if((d[i]<=p[j]&&p[j]<yy&&yy<=L)){
					as1++;
					break;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				if((yy<p[j]&&yy>=0&&yy<=L)){
					as1++;
					break;
				}
			}
		}
	}
	cout << as1 << " " << m-1 << "\n";
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		sv();
	}
	return 0;
}
