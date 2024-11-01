#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,maxn=0;
long long ans=0;
int a[N];
int dp[N];
vector<int> x;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	for(int i = 1;i <= n;i++){
		if(a[i]==maxn){
			x.push_back(i);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[j]>a[i]){
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
	}
	for(int i = 0;i < x.size();i++){
		ans+=dp[x[i]];
	}
	if(maxn==2 || maxn==3) printf("%lld",ans);
	else printf("%lld",n-ans);
	return 0;
}
