#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool get(int x,int t){
	return (x>>(t-1))&1;
}
int main(){
freopen("color.in","r",stdin);
freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		long long ans=0;
		for(int i=0;i<(1<<n);i++){
			bool k;int lastr=0,lastb=0;
			long long tot=0;
			for(int j=1;j<=n;j++){
				k=get(i,j);
				if(k){
					if(a[j]==lastr)tot+=a[j];
					lastr=a[j];
				}
				else{
					if(a[j]==lastb)tot+=a[j];
					lastb=a[j];
				}
			}
			ans=max(ans,tot);
		}
		cout<<ans<<endl;
	}
	return 0;
}