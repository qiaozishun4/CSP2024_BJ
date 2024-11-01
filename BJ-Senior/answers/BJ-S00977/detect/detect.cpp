#include<bits/stdc++.h>
using namespace std;
int p[100005],d[100005],v[100005],a[100005];
bool flag[100005],vis[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		set<int> se;
		int n,m,l,V,ans2=0,ans1=0;
		scanf("%d%d%d%d",&n,&m,&l,&V);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(d[i]<=p[j]){
					long long P=(long long)v[i]*(long long)v[i]+2LL*a[i]*(p[j]-d[i]);
					if(1ll*V*V<P){
						flag[j]=1;
						vis[i]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]) ans1++;
			else vis[i]=0;
		}
		for(int j=1;j<=m;j++){
			if(!flag[j]) ans2++;
			else flag[j]=0;
		}
		printf("%d %d\n",ans1,ans2);
	}
return 0;
}