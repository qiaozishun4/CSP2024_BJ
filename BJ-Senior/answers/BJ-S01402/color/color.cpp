#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+5,H=1e6+5;
int t,n,a[N],h[H],cnt[N],last,mx,tot,ans,f[N];
void dfs(int x){
    if(x>n){
        cnt[1]=cnt[2]=0;
        int s=0;
        for(int i=1;i<=n;i++){
            if(a[cnt[f[i]]]==a[i])
                s+=a[i];
            cnt[f[i]]=i;
        }
        ans=max(ans,s);
        return;
    }
    f[x]=1;
    dfs(x+1);
    f[x]=2;
    dfs(x+1);
}
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans=0;
//        tot=0;
//        mx=0;
//        for(int i=1;i<=n;i++)
//            tot+=(a[i]==a[i-1])*a[i],f[i]=cnt[i]=0;
//        for(int i=1;i<=1e6;i++)
//            h[i]=0;
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<i;j++)
//            cnt[i]=cnt[i-1]+(a[i]==a[i-1])*a[i];
//            f[i]=max(f[i-1],mx);
//            mx+=(a[i]==a[i-1])*a[i];
//            mx=max(mx,f[i-1]);
//            if(i>1&&a[i]==a[i-2])
//                mx=max(mx,f[i-1]+a[i]);
//            if(h[a[i]]>0)
//                f[i]=max(f[i],f[h[a[i]]]+cnt[i-1]-cnt[h[a[i]]]+a[i]);
//            h[a[i]]=i;
//            ans=max(ans,f[i]+tot-cnt[i]);
//        }
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
