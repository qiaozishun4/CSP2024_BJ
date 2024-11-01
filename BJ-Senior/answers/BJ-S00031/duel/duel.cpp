#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int n,out,now;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]>a[out+1]) out++;
	}
	printf("%d",n-out);
	return 0;
}