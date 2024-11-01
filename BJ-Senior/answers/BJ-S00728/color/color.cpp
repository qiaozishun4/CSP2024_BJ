#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXNA=1e2+2,MAXNB=2e5+2,MAXA=12,MAXAB=1e6+2;
int t,n,mxa;
ll ans;
int a[MAXNB],vis[MAXAB];
ll dpa[MAXNA][MAXNA][MAXNA],dpb[MAXNB][MAXA][MAXA];
inline void dodpa(){
    ans=0;
    memset(dpa,0,sizeof(dpa));
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                if(j==k) continue;
                dpa[i+1][i][k]=max(dpa[i][j][k]+(a[i]==a[j])*a[i],dpa[i+1][i][k]);
                dpa[i+1][j][i]=max(dpa[i][j][k]+(a[i]==a[k])*a[i],dpa[i+1][j][i]);
                ans=max(dpa[i][j][k],ans);
            }
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i-j) ans=max(dpa[n+1][i][j],ans);
    return;
}
inline void dodpb(){
    ans=0;
    memset(dpb,0,sizeof(dpb));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            if(!vis[j]||vis[j]>=i) continue;
            for(int k=1;k<=10;k++){
                if(!vis[k]||vis[k]>=i) continue;
                dpb[i+1][a[i]][k]=max(dpb[i][j][k]+(a[i]==j)*j,dpb[i+1][a[i]][k]);
                dpb[i+1][j][a[i]]=max(dpb[i][j][k]+(a[i]==k)*k,dpb[i+1][j][a[i]]);
                ans=max(dpb[i][j][k],ans);
            }
        }
    }
    for(int i=1;i<=10;i++){
        if(!vis[i]) continue;
        for(int j=1;j<=10;j++){
            if(!vis[j]) continue;
            ans=max(dpb[n+1][i][j],ans);
        }
    }
    printf("%lld\n",ans);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        mxa=0;
        memset(vis,false,sizeof(vis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            mxa=max(a[i],mxa);
            if(!vis[a[i]]) vis[a[i]]=i;
        }
        if(n<=100) dodpa();
        else if(mxa<=10) dodpb();
    }
    return 0;
}
