#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

ll n,x,now,ans;
ll a[N];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x);
		a[x]++;
	}
	/*for(ll i=1;i<=5;i++){
		cout<<a[i]<<" ";
	}*/
	for(ll i=1;i<=N;i++){
		if(a[i]!=0){
			if(now==0){
				now=a[i];
			}else if(now>=a[i]){
				ans+=a[i];
			}else{
				ans+=now;
				now=a[i];
			}
		}
	}
	printf("%lld\n",n-ans);
	return 0;
}
