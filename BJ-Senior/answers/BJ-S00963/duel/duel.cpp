#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],now,cnt;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		now++;
		if(a[i]!=a[i-1]) cnt=1;
		else cnt++;
		if(cnt<now) now--;
	}
	printf("%d",now);
	return 0;
}
