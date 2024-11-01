#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct query{int q,id;}c[N];
int cmp(query x,query y){return x.q<y.q;}
int n,m,K,_,a_[N],a[N],x[4];
char d[22][N];
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a_[i]);
	for(int i=1;i<=m;i++) scanf("%d",&c[i].q),c[i].id=i;
	sort(c+1,c+m+1,cmp);
	K=log2(n);
	if((1<<K)<n) K++;
	for(int i=1;i<=K;i++) cin>>d[i];
	scanf("%d",&_);
	while(_--){
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		for(int i=1;i<=n;i++) a[i]=a[i]^x[i%4];
		long long ans=0;
		for(int i=1;i<=m;i++) ans+=1ll*i*n*(n-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
