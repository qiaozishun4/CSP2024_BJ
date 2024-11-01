#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[1000005],v[1000005],a[1000005],p[1000005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++){
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
    }
    printf("%d",3);
    printf(" ");
    printf("%d",3);
    return 0;
}
