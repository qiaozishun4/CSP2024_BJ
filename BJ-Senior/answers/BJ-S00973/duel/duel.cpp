#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005],x,y,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	x=1;
	for(y=2;y<=n;y++){
		if(a[y]>a[1]) break;
	}
	ans=n;
	while(y<=n){
		if(a[y]>a[x]){
			ans--;
			x++;y++;
		}else{
			y++;
		}
	}
	printf("%lld",ans);
	return 0;
}
