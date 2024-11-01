#include<bits/stdc++.h>
using namespace std;
int t,n,ans,Ans=-1;
int num[1005];
bool c[1005];
int color[2];
void dfs(int w,int l){
	if(w==n+1){
		ans=0;
		color[0]=-1,color[1]=-1;
		for(int i=1;i<=n;i++){
			if(color[c[i]]==num[i])ans+=num[i];
			color[c[i]]=num[i];
		}
		Ans=max(Ans,ans);
		return;
	}
	c[w]=l;
	dfs(w+1,0);
	dfs(w+1,1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		Ans=-1;
		ans=0;
		memset(c,0,1000);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		dfs(1,0);
		ans=0;
		memset(c,0,1000);
		dfs(1,1);
		printf("%d\n",Ans);
	}
	return 0;
}