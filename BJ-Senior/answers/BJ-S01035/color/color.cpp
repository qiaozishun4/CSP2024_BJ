#include<bits/stdc++.h>
using namespace std;
int a,b[1000005],p[100005],ans;
void dfs(int st){
	if(st==a+1){
		int pans=0;
		for(int i=1;i<=a;i++){
			for(int j=i-1;j>=1;j--){
				if(p[i]==p[j]&&b[i]==b[j]){
					pans+=b[i];
					break;
				}
				if(p[i]==p[j])break;
			}
		}
		ans=max(ans,pans);
		return ;
	}
	p[st]=1;
	dfs(st+1);
	p[st]=0;
	dfs(st+1);
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		for(int i=1;i<=a;i++){
			scanf("%d",&b[i]);
		}
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
}
