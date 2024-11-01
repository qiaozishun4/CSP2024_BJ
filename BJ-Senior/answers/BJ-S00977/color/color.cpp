#include<bits/stdc++.h>
using namespace std;
int f[200005];
int a[200005],n,T;
long long ans=-1e18;
inline void c(){
	long long sum=0;
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(a[i]==a[j]&&f[i]==f[j]){sum+=a[j];break;}
	ans=max(ans,sum);
}
void dfs(int k){
	if(k>n){c();return;}
	for(int i=0;i<=1;i++){
		f[k]=i;
		dfs(k+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=-1e18;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		dfs(1);
		printf("%lld\n",ans);
	}
  return 0;
}