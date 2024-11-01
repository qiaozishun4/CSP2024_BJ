#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V,t;
long long d[100000],v[100010],a[1000100],p[100011];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(v[i]>V&&d[i]>=p[1]){
				ans++;
			}
		}  
		if(ans>0){
			cout<<ans<<" "<<m-1<<endl;
		}else{
			cout<<ans<<" "<<m<<endl;
		}
	}
	return 0;
}
