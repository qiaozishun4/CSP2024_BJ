#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200005],ans;
bool h[1000005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		for(long long i=0;i<=1e6;i++){
			h[i]=0;
		}
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			if(h[a[i]]){
				ans+=a[i];
			}else{
				h[a[i]]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}