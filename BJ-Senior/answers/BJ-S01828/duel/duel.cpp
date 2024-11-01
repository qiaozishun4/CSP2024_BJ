
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N int(1e5+10)
using namespace std;
int a[N],n,minn=INF,ans,l,r;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;++i) cin>>a[i],minn=min(minn,a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		if(a[i]==minn&&!l) l=i;
		else if(a[i]!=minn){
			r=i;
			break;
		}
	}
	while(l<r&&r<=n){
		if(a[r]>a[l]){
			ans--;
			l++,r++;
		}else if(a[r]==a[l]) r++;
	}
	cout<<ans<<'\n';
	return 0;
}