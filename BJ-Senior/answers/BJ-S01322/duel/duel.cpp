#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[20010];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int q=unique(a+1,a+1+n)-a-1;
	cout<<n-q;
	return 0;
}