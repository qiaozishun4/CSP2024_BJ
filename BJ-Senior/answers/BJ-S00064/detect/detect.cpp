#include<bits/stdc++.h>
using namespace std;
int d[1000001],v[1000001],a[1000001];
int ll[1000001];
int is[3001][3001];
int chebing[1000001];
int t,n,m,l,vl;
struct sujj{
	int x,i;
}shu[1000001];
bool sor(sujj x,sujj y){
		return x.x<y.x?true:false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
//	printf("1");
	scanf("%d",&t);
	while(t--){
		memset(chebing,0,sizeof(chebing));
		for(int i=1;i<=10000;i++){
				shu[i].x=0;
				shu[i].i=i;
		}
		memset(is,0,sizeof(is));
		int ans=0;
			scanf("%d%d%d%d",&n,&m,&l,&vl);
			int shan=m;
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&d[i],&v[i],&a[i]);
				
			}
			for(int i=1;i<=m;i++){
					int x;
					scanf("%d",&x);
					ll[i]=x;
					
			}
			for(int i=1;i<=n;i++){
					int k;
					if(a[i]!=0) k=(vl*vl-v[i]*v[i])/2/a[i];
					if(a[i]==0){
						 if(v[i]<vl) continue;
						 else k=m-d[i];
					}
	//				printf("1");
					for(int j=1;j<=m;j++){
							if(ll[j]<=d[i]+k&&ll[j]>=d[i]){
								 if(chebing[i]==0) ans++;
								 chebing[i]++;
								 shu[j].x++;
								 shu[j].i=j;
								 is[j][shu[j].x]=i;

							}
					}
					
			}
			sort(shu+1,shu+m+1,sor);
			for(int i=1;i<=m;i++){
				int k=shu[i].i,flag=0;
				for(int j=1;j<=shu[i].x;j++){
						if(chebing[is[k][j]]<=1){
							flag=1;
							break;
						} 
				}
				if(flag==0) shan--;
				else continue;
				for(int j=1;j<=shu[i].x;j++){
						if(chebing[is[k][j]]>1){
							chebing[is[k][j]]--;
						}
				}
			}
			printf("%d %d",ans,m-shan);
	}

	fclose(stdin);
	fclose(stdout);
}
