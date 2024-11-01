#include<iostream>
using namespace std;
typedef long long ll;
const ll inf=1000000000000000000,lim=1000000;
ll t,h[1000005],n,a[200005],s[200005],f[200005],g[200005],mx,ans,mxs;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			f[i]=g[i]=-inf;
			cin>>a[i];
			if(i>=2){
				s[i]=s[i-1]+(a[i-1]==a[i])*a[i];
			}
		}
		for(ll i=1;i<=lim;i++){
			h[i]=-inf;
		}
		mx=ans=mxs=-inf;
		for(ll i=1;i<=n;i++){
			if(i==1){
				f[i]=0;
			}
			else{
				f[i]=s[i-1]-s[1];
			}
			if(i>=2){
				mxs=max(mxs,f[i-1]-s[i-1]);
				if(i>=3){
					h[a[i-2]]=max(h[a[i-2]],f[i-1]-s[i-1]+a[i-2]);
				}
			}
			if(i>=2){
				f[i]=max(f[i],mxs+s[i-1]);
				f[i]=max(f[i],h[a[i]]+s[i-1]);
			}
			mx=max(mx,f[i]-s[i]);
			g[i]=mx+s[i];
		}
		ans=max(ans,g[n]);
		cout<<ans<<endl;
	}
	return 0;
}
