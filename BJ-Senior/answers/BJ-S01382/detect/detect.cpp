#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[100001],v[100001],a[100001],p[100001],sp[1000001],ans;
bool exAB=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		int j=1;
		for(int i=1;i<=L;i++){
			if(i==p[j]){
				sp[i]=1;
				j++;
			}
			else sp[i]=0;
			sp[i]+=sp[i-1];
		}
		for(int i=1;i<=n;i++){
			//cout<<i<<":\n";
			if(a[i]<0){
				exAB=0;
				//t<(V-v[i])/a[i]
				//s<(V^2-v[i]^2)/(2a[i])
				if(v[i]>=V){
					if(sp[min(L,d[i]+(V*V-v[i]*v[i]-1)/(2*a[i]))]-sp[d[i]-1]) ans++;
					//cout<<"outlaw"<<d[i]<<'~'<<min(L,d[i]+(V*V-v[i]*v[i]-1)/(2*a[i]))<<'\n';
				}
			}
			if(a[i]==0){
				if(v[i]>V){
					if(sp[L]-sp[d[i]-1]) ans++;
					//cout<<"outlaw"<<'\n';
				}
			}
			if(a[i]>0){
				if(V<v[i]){
					if(sp[L]-sp[d[i]-1]) ans++;
				}
				else if(d[i]+(V*V-v[i]*v[i])/(2*a[i])+1<=L){
					if(sp[L]-sp[d[i]+(V*V-v[i]*v[i])/(2*a[i])]) ans++;
					//cout<<"outlaw"<<d[i]+(V*V-v[i]*v[i])/(2*a[i])+1<<'~'<<L<<'\n';
				}
			}
		}
		cout<<ans<<' ';
		if(exAB){
			if(ans!=0) cout<<m-1<<'\n';
			else cout<<m<<'\n';
			continue;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
