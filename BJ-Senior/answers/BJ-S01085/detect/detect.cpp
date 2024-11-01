#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V;
int d[100005],v[100005],a[100005],p[100005];
int range[100005][2],ans1,ans2,vis[100005],rmin=1e9,rmax=0;
double calc;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		ans1=0,ans2=0,rmin=1e9,rmax=0;
		cin>>n>>m>>L>>V;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i = 1;i <= m;i++){
			scanf("%d",&p[i]);
		}
		for(int i = 1;i <= n;i++){
			range[i][0]=1e9;
			range[i][1]=-1;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(p[j]<d[i]) continue;
				if(a[i]!=0){
					calc=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
				}else{
					calc=v[i];
				}
				if(calc>V){
					range[i][0]=min(range[i][0],j);
					rmin=min(rmin,range[i][0]);
					rmax=max(rmax,range[i][0]);
					if(vis[i]==0){
						ans1++;
						vis[i]=1;
					}
				}else{
					range[i][1]=max(range[i][1],j);
				}
			}
		}
		memset(vis,0,sizeof(vis));
		cout<<ans1<<" ";
		ans2=(rmin-1)+(m-rmax);
		for(int i = 1;i <= n;i++){
			for(int j = rmin+1;j < rmax;j++){
				if(range[i][0]==rmin || range[i][0]==rmax) continue;
				if(range[i][0]<j && range[i][1]>j) vis[j]=1;
				else if(range[i][0]>j || range[i][1]<j) vis[j]=1;
				else vis[j]=0;
			}
		}
		for(int i = 1;i <= m;i++){
			if(vis[i]==1) ans2++;
		}
		cout<<ans2<<endl;
	}
	return 0;
}
				
