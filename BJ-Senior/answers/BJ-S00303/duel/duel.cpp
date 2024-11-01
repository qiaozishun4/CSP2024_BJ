#include<bits/stdc++.h>
using namespace std;
int r[100005];
int n,x,maxx=-1,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		r[x]++;
		maxx=max(maxx,x);
	}
	ans=r[1];
	for(int i=2;i<=maxx;i++){
		ans=max(ans-r[i],0);
		ans+=r[i];
	}
	printf("%d",ans);
	return 0;
}