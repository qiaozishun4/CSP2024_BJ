#include<bits/stdc++.h>
using namespace std;
#define int long long
struct m{
	int l;
	int r;
	int id;
}le[1000005];
int a,b,c,d,s[1000005],n[1000005],ja[1000005],p[1000005];
bool cmp(m a,m b){
	return a.l<b.l;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--){
		int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		for(int i=1;i<=a;i++){
			scanf("%lld%lld%lld",&s[i],&n[i],&ja[i]);
		}
		for(int i=1;i<=b;i++){
			scanf("%lld",&p[i]);
			if(p[i]>c)p[i]=1e9;
		}
		int fans=0;
		for(int i=1;i<=a;i++){
			le[i].l=100000000;
			le[i].r=0;
			le[i].id=i;
		}
		for(int i=1;i<=a;i++){
			if(ja[i]<0){
				int m=(d*d-n[i]*n[i])/(2*ja[i])+s[i];
				if((d*d-n[i]*n[i])%(2*ja[i])!=0)m++;
				for(int j=1;j<=b;j++){
					if(p[j]<m&&p[j]>=s[i]){
						le[i].l=min(le[i].l,j);
						le[i].r=max(le[i].r,j);
					}
				}
			}else{
				if(ja[i]>0){
					int m=(d*d-n[i]*n[i])/(2*ja[i])+s[i];
					for(int j=1;j<=b;j++){
						if(p[j]<m&&p[j]>=s[i]){
							le[i].l=min(le[i].l,j);
							le[i].r=max(le[i].r,j);
						}
					}
				}else{
					for(int j=1;j<=b;j++){
						if(n[i]>d&&p[j]>=s[i]){
							le[i].l=min(le[i].l,j);
							le[i].r=max(le[i].r,j);
						}
					}
				}
			}
		}
		
		sort(le+1,le+a+1,cmp);
		for(int i=1;i<=a;i++){
			if(le[i].l!=100000000)fans++;
		}
		int now=1e9,nw=a,ans=0;
		while(1){
			if(nw==0)break;
			if(le[nw].l==100000000){
				nw--;
				continue;
			}
			if(now>le[nw].r){
				ans++;
				now=le[nw].l;
			}
			nw--;
		}
		printf("%lld %lld\n",fans,b-ans);
	}
}
