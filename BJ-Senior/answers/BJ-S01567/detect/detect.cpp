#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,sum;
int d[100001],v[100001],a[100001],p[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        sum=0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++){
            if(d[i]<=p[m]&&v[i]>V){
                sum++;
            }
        }
        if(sum==0){
            printf("%d %d\n",sum,m);
        }else{
            printf("%d %d\n",sum,m-1);
        }
    }
    return 0;
}