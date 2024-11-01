#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d[100000],v[100000],a[100000],h[100000];
int ans,ans1,idx;
long long sudu(int r,int l,int p,int y){
    return (2*p)/(V*V-v[y]*v[y]);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        idx=0;
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int j=1;j<=n;j++){
                if(j==n-1){
                    for(int x=1;x<=m;x++){
                        scanf("%d",h[i]);
                    }
                }else{
                    scanf("%d%d%d",&d[++idx],&v[++idx],&a[++idx]);
                }
        }
        for(int y=1;y<=n;y++){
            if(sudu(d[i],v[i],a[i],y)>V){
                ++ans;
            }
        }
        int o=34;
        printf("%d %d",&ans,&o);
    }
    return 0;
}

