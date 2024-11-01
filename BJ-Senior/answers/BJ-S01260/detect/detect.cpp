#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
bool flag0;
int n,m,l,v;
int d[N],vi[N],ai[N];
ll VV,dis,vmax;
int ans,p[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        flag0 = false;
        ans = 0;
        scanf("%d %d %d %d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&d[i],&vi[i],&ai[i]);
            if(ai[i] != 0) flag0 = true;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        if(!flag0){
            for(int i=1;i<=n;i++){
                if(d[i]<=p[m] && vi[i] > v) ans++;
            }
            if(ans == 0) printf("%d %d\n",ans,m);
            else printf("%d %d\n",ans,m-1);
            continue;
        }
        VV = v*v;
        for(int i=1;i<=n;i++){
            if(p[m] < d[i]) continue;
            dis = p[m] - d[i];
            vmax = 2*ai[i]*dis+vi[i]*vi[i];
            if(vmax > VV) ans++;
        }
        if(ans == 0) printf("%d %d\n",ans,m);
        else printf("%d %d\n",ans,m-1);
    }
    return 0;
}
