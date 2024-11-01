#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
int t[25][25];
int d[N],v[N],a[N];
int P[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,L,V;
		scanf("%d %d %d %d",&n,&m,&L,&V);
		int ans1=0,ans2=0;
		
		bool sp1=true,sp2=true;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
			if(a[i]!=0){
				sp1=false;
			}
			if(a[i]<0){
				sp2=false;
			}
		}
		int maxs=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&P[i]);
			maxs=max(maxs,P[i]);
		}
		sort(P+1,P+1+m);
		if(sp1){
			//printf("OK");
			for(int i=1;i<=n;i++){
				if(d[i]<=maxs&&v[i]>V){
					ans1++;
				}
			}
			printf("%d ",ans1);
			if(ans1) printf("%d\n",m-1);
			else printf("%d\n",0);
			continue;
		}
		for(int i=1;i<=n;i++){
			vis[i]=false;
			for(int j=1;j<=m;j++){
				t[j][i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=1;j<=m;j++){
				if(P[j]>=d[i]){
					int x=P[j]-d[i];
					long long v2=v[i]*v[i]+2*a[i]*x;
					if(v2>V*V){
						flag=1;
						if(!sp2){
							t[j][i]=1;
						}
						continue;
					}
					double v=sqrt(v2);
					if(v>V){
						flag=1;
						if(!sp2){
							t[j][i]=1;
						}
					}
				}
			}
			if(flag){
				ans1++;
			}
		}
		printf("%d ",ans1);
		if(sp2){
			if(ans1) printf("%d\n",m-1);
			else printf("%d\n",0);
			continue;
		}
		for(int i=1;i<=n;i++){
			vis[i]=false;
		}
		for(int i=0;i<=(1<<m)-1;i++){
			int s=i;
			int j=1;
			for(int k=1;k<=n;k++){
				vis[k]=0;
			}
			int tot=0;
			//s=(1<<m)-1;
			while(s>(1<<(j-1))){
				
				if(s&(1<<(j-1))){
					tot++;
					//printf("%d\n",j);
					for(int k=1;k<=n;k++){
						if(t[j][k]){
							vis[k]=1;
						}
					}
				}
				j++;
			}
			int cnt=0;
			for(int k=1;k<=n;k++){
				if(vis[k]==1){
					cnt++;
				}
			}
			//printf("%d\n",cnt);
			if(cnt==ans1){
				
				ans2=max(ans2,m-tot);
			}
		}
		printf("%d\n",ans2);
	}
	return 0;
}