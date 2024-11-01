#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
ll T,n,a[N],cnt[N],f[N][3],sum,p;
int main(){
	freopen("color,in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt[i]=cnt[i]+a[i];
			}
			else{
				cnt[i]=cnt[i-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=0;k<=1;k++){
				for(int j=i-1;j>=1;j--){
					for(int o=0;o<=1;o++){
						if(k==o){
							p=a[i]==a[j]?a[i]:0;
							if(i-k>=2){
								sum=f[j][k]+cnt[i-1]-cnt[j+1]+p;
							}
							else{
								sum=f[j][k]+p;
							}
							f[i][k]=max(f[i][k],sum);
						}
					}
				}
			}
		}
		printf("%lld",max(f[n][0],f[n][1]));
	}
	return 0;
}
						
