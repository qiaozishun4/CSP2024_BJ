#include <bits/stdc++.h>
using namespace std;
int n,ans,maxn,a[100005],book[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],++book[a[i]],maxn=max(maxn,book[a[i]]);
	cout<<maxn;
	return 0;
}
