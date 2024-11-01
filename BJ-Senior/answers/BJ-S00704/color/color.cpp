#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,t,a[N],c[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        n=0;int ans=0;
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        for(int i=0;i<=(1<<n)-1;i++){
            int b[25],u=i,k=0;
            memset(b,0,sizeof b);
            memset(c,0,sizeof c);
            while(u){
                b[++k]=u&1;
                u>>=1;
            }
            int cnt=0;
            for(int j=2;j<=n;j++)
                for(int l=j-1;l;l--)
                    if(b[l]==b[j])
                        if(a[l]==a[j]) c[j]=a[j];
            for(int j=1;j<=n;j++) cnt+=c[j];
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}