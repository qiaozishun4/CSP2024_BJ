#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[3005],v[3005],a[3005],p[3005],b[3005];
vector<int>l[3005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll T;
    scanf("%lld",&T);
    while(T--){
        int n,m,L,V,ans1=0,ans2=0;
        memset(d,0,sizeof(d)),memset(v,0,sizeof(v)),memset(a,0,sizeof(a)),memset(p,0,sizeof(p)),memset(b,0,sizeof(b));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%lld",&p[i]);
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                double x=(V*V-v[i]*v[i])*1.0/2/a[i]+d[i];
                if(x<=p[m]){
                    ans1++;
                    int y=upper_bound(p+1,p+m+1,x)-p;
                    for(int j=y;j<=m;j++)l[i].push_back(j);
                }
            }
            if(a[i]==0){
                if(v[i]>V&&d[i]<=p[m]){
                    int x=upper_bound(p+1,p+m+1,d[i])-p;
                    ans1++;
                    for(int j=x;j<=m;j++)l[i].push_back(j);
                }
            }
            if(a[i]<0){
                if(v[i]<=V)continue;
                double x=(V*V-v[i]*v[i])*1.0/2/a[i]+d[i];
                int y=lower_bound(p+1,p+m+1,d[i])-p;
                int z=lower_bound(p+1,p+m+1,x)-p-1;
                if(y<=z){
                    ans1++;
                    for(int j=y;j<=z;j++)l[i].push_back(j);
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(b[i]==0)ans2++;
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}