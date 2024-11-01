#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int N=1e5+5;
int T,n;
lol f[N],g[N],a[N],h[N];
lol get(int l,int r){
    if(l>r) return 0;
    return g[r]-g[l];
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(g,0,sizeof(g));
        memset(f,0,sizeof(f));
        memset(h,0,sizeof(h));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]) g[i]=g[i-1]+a[i];
            else g[i]=g[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                f[i]=max(f[i],h[j-1]+get(j,i));
                h[i]=max(h[i],f[i]+((a[j-1]==a[i+1])?a[i+1]:0));
            }
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}
