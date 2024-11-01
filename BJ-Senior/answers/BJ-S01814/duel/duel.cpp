#include<bits/stdc++.h>
using namespace std;

const int w=1e5;

int n;
int a[100005],cnt[100005];
int ans;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	for(int i=1;i<=w;++i){
		ans=max(ans,cnt[i]);
	}
	cout<<ans;
	return 0;
}
