#include <bits/stdc++.h>
using namespace std;
int ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T,n,a[100000],b[100000];
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        ans=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        scanf("%d",a[1]);
        for(int j=2;j<=n;j++){
            scanf("%d",a[i]);
            for(int x=j-1;x>=1;x--){
                if(a[x]==a[j]){
                    b[j]=a[x];
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++) ans+=b[i];
        printf("%d",&ans);
    }
    return 0;
}