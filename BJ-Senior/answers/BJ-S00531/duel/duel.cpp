#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int h[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		h[x]++;
		ans=max(ans,h[x]);
	}
	printf("%d",ans);
	return 0;
}
