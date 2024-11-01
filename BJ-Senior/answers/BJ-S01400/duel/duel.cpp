#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;

ll n,a[N],cnt[N],ans;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
		ans=max(ans,cnt[a[i]]);
	}
	printf("%lld",ans);
	return 0;
}
