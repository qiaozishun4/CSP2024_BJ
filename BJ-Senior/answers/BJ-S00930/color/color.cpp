#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
int a[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		int head0=0,head1=0,sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(a[j+1]==head1){
					sum+=a[j+1];
				}head1=a[j+1];
			}else{
				if(a[j+1]==head0){
					sum+=a[j+1];
				}head0=a[j+1];
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
