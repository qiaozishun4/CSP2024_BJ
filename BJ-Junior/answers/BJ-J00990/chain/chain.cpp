#include<bits/stdc++.h>
using namespace std;
long long T,a[1001][2001],p[1001],n,k,q,r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%lld",&T);
	for(int i=1;i<=T;i++){
		scanf("%lld %lld %lld",&n,&k,&q);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j][0]);
			for(int x=1;x<=a[j][0];x++) scanf("%lld",&a[j][x]);
		}
		for(int j=1;j<=q;j++){
			scanf("%lld %lld",&r,&c);
			int ml=0xffffff;
			if(r==1){
				for(int x=1;x<=n;x++){
					for(int s=1;s<=a[x][0];s++){
						if(a[x][s]==c){
							ml=min(ml,s);
							break;
						}
					}
				}
				if(ml>k) printf("0\n");
				else printf("1\n");
			}
		}
	}
	return 0;
}
