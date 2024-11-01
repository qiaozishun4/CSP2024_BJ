#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long t;
	cin>>t;
	long long n;
	long long ans=0;
	while(t--){
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			for(long long j=1;j<i;j++){
				if(a[j]==a[i]&&i!=1){
					ans+=a[i];
					break;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		memset(a,0,sizeof(a));
	}
	return 0;
}
