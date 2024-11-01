#include<bits/stdc++.h>
using namespace std;
int a[100100],m[100100],dp[100100][3];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,mi=1e9,ans;
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>mi) ans--;
		mi=min(mi,a[i]);
	}
	cout<<ans;
	return 0;
}