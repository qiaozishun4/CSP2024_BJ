#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long n,T,ans=0;
	scanf("%lld",&T);
	while(T--){
		memset(a,0,sizeof(a));ans=0;
		scanf("%lld",&n);
		for(int i=1,t;i<=n;i++){
			scanf("%d",&t);
			a[t]++;
		}
		for(int i=1;i<=1e6;i++)	ans+=max((a[i]-1)*i,0);
		printf("%lld\n",ans);
	}
    return 0;
}

