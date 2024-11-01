#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,last,len,vis[200005],r,c,v;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	
	while(t--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&len);
			last=-10000000;
			for(int j=1;j<=len;j++){
				scanf("%d",&v);
				if(j-last+1<=k){
					vis[v]=1;
				}
				if(v==1) last=j;
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&r,&c);
			if(vis[c]==1){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
				
		}
	}
	return 0;
}
