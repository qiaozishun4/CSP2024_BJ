#include<bits/stdc++.h>
using namespace std;
int mp[100005][200005];
int visb[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,k,q;
		scanf("%d %d %d",&n,&k,&q);
		for(int j=1;j<=n;j++){
			int p;
			scanf("%d",&p);
			for(int x=1;x<=p;x++){
				scanf("%d",&mp[j][x]);
				visb[mp[j][x]]++;
			}
		}
		for(int j=1;j<=q;j++){
			int r,c;
			scanf("%d %d",&r,&c);
			if(visb[c]==0)
				printf("%d\n",0);
			else
				printf("%d\n",1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
