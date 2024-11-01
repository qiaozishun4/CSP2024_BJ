#include<iostream>
#include<cmath>
using namespace std;
long long a[10000005],t,n,ans=0;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		ans=0;
		cin>>n;
		for(long long j=1;j<=n;j++){
			cin>>a[j];
			if(j!=1){
				for(long long k=1;k<j;k++){
					if(a[j]==a[k]){
						ans+=a[j];
						break;
					}
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}
