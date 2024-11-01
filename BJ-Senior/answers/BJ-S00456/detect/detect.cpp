#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m,L,Vm,sym,p[N],vis[N],d[N],v[N],a[N],l[N],r[N];
int flag,dis,op,ans1,ans2;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&Vm);
		flag=0,ans1=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]<0)  sym=1;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		if(!sym){
			for(int i=1;i<=n;i++){
				flag=0;
				if(a[i]==0){
					if(v[i]>Vm){
						flag=1;
						l[i]=d[i],r[i]=L;
					}
				}
				else if(a[i]>0){
					op=sqrt(2*a[i]*(L-d[i])+v[i]);
					if(op*op!=(2*a[i]*(L-d[i])+v[i]))  op++;
					if(op>Vm){
						flag=1;
						dis=(Vm*Vm-v[i]*v[i])/(2*a[i]);
						if(dis*2*a[i]!=Vm*Vm-v[i]*v[i])  dis++;
						l[i]=d[i]+dis,r[i]=L;
						if(l[i]>L)  l[i]=L;
					}
				}
				if(flag){
					if(a[i]>0&&l[i]>p[m])  continue;
					else if(a[i]==0&&d[i]>p[m])  continue;
					ans1++;
				}
			}
			if(ans1==0)  ans2=m;
			else  ans2=m-1;
			printf("%d %d\n",ans1,ans2);
		}
	}
	return 0;
}
		
		
		
