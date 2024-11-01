#include<bits/stdc++.h>
using namespace std;
long long n,a[10000000],c[10000000],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(a[j]>a[i]&&c[j]!=1){
				a[i]=-1;
				c[j]=1;
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
}
