#include <bits/stdc++.h>
using namespace std;
int T,n,a[200010],ans,ma,j;
bool co[200010];
void dfs(int x){
	if(x==n){
		ans=0;
		for(int i=1;i<=n;i++){
			if(i==1) continue;
			for(j=i-1;j>=0&&co[i]!=co[j];j--){
				if(a[i]==a[j]) ans+=a[i];
			}
		}
		ma=max(ans,ma);
		return ;
	}
	dfs(x+1);
	co[x+1]=1;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ma=0;
		scanf("%d",&n);
		a[0]=-21;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			co[i]=0;
		}
		dfs(0);
		printf("%d\n",ma);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
