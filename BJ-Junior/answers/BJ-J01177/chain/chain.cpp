#include<bits/stdc++.h>
using namespace std;
int len[100005],l[100005];
bool flag;
int n,q,s,c;
void dfs(int f,int k){
	if(flag) return;
	if(k>s){
		for(int i=1;i<=len[f];i++) if(l[i]==c){flag=1;break;}
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=f){
			if(f==0){
				for(int j=1;j<=len[i];j++) if(l[j]==1){dfs(j,k+1);break;}
			}
			else{
				dfs(i,k+1);
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int k;
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&len[i]);
			for(int j=1;j<=len[i];j++){
				scanf("%d",&l[j]);
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&s,&c);
			dfs(0,1);
			if(flag) printf("1\n");
			else printf("0\n");
			flag=0;
		}
	}
	return 0;
}