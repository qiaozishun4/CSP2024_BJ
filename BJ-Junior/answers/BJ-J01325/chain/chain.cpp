#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,q,k;
int t,l[N];
vector<int>mp[N];
int r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				int t;
				scanf("%d",&t);
				mp[i].push_back(t);
			}
		}
		while(q--){
			scanf("%d%d",&r,&c);
			int f=0;
			for(int i=1;i<=n;i++){
				for(int j=2;j<=k;j++)if(mp[i][j]==c)f=1;
				if(f){
					break;
				}
			}
			printf("%d\n",f);
		}
		for(int i=1;i<=n;i++)mp[i].clear();
		for(int i=1;i<=n;i++)l[i]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}