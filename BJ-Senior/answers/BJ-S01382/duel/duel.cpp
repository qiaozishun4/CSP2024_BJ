#include<bits/stdc++.h>
using namespace std;
int n,c,ans,a[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[c]++;
		ans=max(ans,a[c]);
	}
	cout<<ans;
	return 0;
}
