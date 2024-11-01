#include<bits/stdc++.h>
using namespace std;
#define N 100010
long long n;
long long xk,mini=100010;
long long r[N];
long long lst[N];
string nl,lsl[N],rl[N];
int main(){
	freopen("duel2.in","r",stdin);
	freopen("duel2.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&xk);
		r[xk]++;
		mini=min(mini,xk);
	}
	printf("%lld\n",r[mini]);
	return 0;
}
