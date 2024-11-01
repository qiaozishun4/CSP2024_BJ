#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
void solve(){
	int n,a[N];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=-INT_MAX;
	for(long long i=0;i<=pow(2,n);i++){
		int now[N];
		int xx=i;
		for(int j=1;j<=n;j++){
			now[j]=xx%2;
			xx/=2;
		}
		int c[N];
		c[1]=0;
		for(int k=2;k<=n;k++){
			c[k]=0;
			for(int j=k-1;j>=1;j--){
				if(now[k]==now[j]){
					if(a[k]==a[j]){
						c[k]=a[k];
					}else{
						c[k]=0;
					}
					break;
				}
			}	
		}
		ll nu=0;
		for(int k=1;k<=n;k++){
			nu+=c[k];
		}
		ans=max(ans,nu);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}