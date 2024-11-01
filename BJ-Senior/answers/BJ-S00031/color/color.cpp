#include <bits/stdc++.h>
using namespace std;
long long a[50];
int cs[50];
long long ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	for(int II=0;II<T;II++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				cs[j]= (i>>(j-1)) & 1;
			}
			long long now[2]={0,0},sum=0;
			for(int j=1;j<=n;j++){
				if(a[j]==a[now[cs[j]]]) sum+=a[j];
				now[cs[j]]=j;
			}
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}