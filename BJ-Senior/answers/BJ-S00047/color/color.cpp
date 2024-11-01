#include <bits/stdc++.h>
using namespace std;
long long t,n,a[200005],b[1000006],e[200005],c[200005],dp[200005][2];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	for(;t;t--){
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[a[i]]=0;
			c[i]=c[i-1];
			if(a[i]==a[i-1])
				c[i]+=a[i];
		}
		for(long long i=1;i<=n;i++){
			dp[i][0]=dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
			if(a[i]==a[i-1])
				dp[i][0]+=a[i];
			for(long long j=b[a[i]];j;j=e[j])
				if(j!=i-1){
					dp[i][1]=max(dp[i][1],dp[j+1][1]+c[i-1]-c[j+1]+a[i]);
				}
			e[i]=b[a[i]];
			b[a[i]]=i;
		}
		printf("%lld\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}