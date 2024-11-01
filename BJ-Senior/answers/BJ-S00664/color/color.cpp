#include <bits/stdc++.h>
#define N 200005
using namespace std;

int T,n,ans,y,e;
int a[N],cnt[N];
int dp[N][5];

void dfs(int now,int deep){
	if(now==deep){
		int f=y=e=0;
		for(int i=1;i<=n;i++){
			if(cnt[i]==1){
				if(a[y]==a[i]){
					f+=a[i];
				}
				y=i;
			}else{
				if(a[e]==a[i]){
					f+=a[i];
				}
				e=i;
			}
		}
		ans=max(ans,f);
		return ;
	}
	for(int i=1;i<=2;i++){
		cnt[now]=1;
		dfs(now+1,deep);
		cnt[now]=2;
		dfs(now+1,deep);
	}
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=y=e=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dfs(0,n);
		printf("%d\n",ans);
	}
	return 0;
}
