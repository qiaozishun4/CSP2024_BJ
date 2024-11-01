#include<bits/stdc++.h>
using namespace std;
int T,N,M,L,V,d[100005],v[100005],a[100005],p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int mx=-1,ans=0;
		cin>>N>>M>>L>>V;
		for(int i=1;i<=N;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=M;i++){
			cin>>p[i];
			mx=max(mx,p[i]);
		}
		for(int i=1;i<=N;i++){
			if(d[i]<=mx&&v[i]>=V){
				ans++;
			}
		}
		cout<<ans<<" "<<M-1<<endl;
	}
	return 0;
}