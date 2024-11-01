#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[100010],v[100010],a[100010],p[100010],ans1,ans2,qz[100010];
int x,s,dis,mi;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		ans1=0;
		ans2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			qz[i]=0;
		}
		sort(p+1,p+1+m,cmp);
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]<=V) continue;
				else {
				//	for(int j=1;j<=m;j++) cout<<p[j]<<' ';
					//printf("\n");
					x=lower_bound(p+1,p+1+m,d[i])-p;
					if(p[x]<d[i]){
				//		cout<<x<<' '<<p[x]<<' '<<d[i]<<endl;
						continue;
					}
					else ans1++;
				}
			}
			else{
				x=lower_bound(p+1,p+1+m,d[i])-p;
				for(int j=x;j<=m;j++){
					dis=p[j]-d[i];
					s=sqrt(v[i]*v[i]+2*a[i]*dis);
					if(s*s==v[i]*v[i]+2*a[i]*dis){
						if(s>V){
							ans1++;
							break;
						}
					}
					else{
						if(s>=V){
							ans1++;
							if(a[i]>0) 
							break;
						}
					}
				}
			}
		}
		printf("%d %d\n",ans1,m-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
