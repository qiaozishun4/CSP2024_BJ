#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int t,n,m,L,V,d[100005],v[100005],a[100005],p[1000005],x,ans1,c[1000005],ans2;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans1=0;
        ans2=0;
        memset(p,0,sizeof(p));
        memset(c,0,sizeof(c));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&x),p[x]=1;
        for(int i=1;i<=n;i++){
            for(int j=d[i];j<=L;j++){
                double s=j-d[i];
                double speed=sqrt(v[i]*v[i]*1.0+2.0*a[i]*s);
                if(speed<=0) break;
                if(p[j] && speed-V>0){
                    ans1++;
                    c[j]=1;
                    break;
                }
            }
        }
        for(int i=1;i<=L;i++) if(p[i] && !c[i]) ans2++;
        printf("%d %d\n",ans1,ans2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
