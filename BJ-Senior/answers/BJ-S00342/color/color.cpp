#include<bits/stdc++.h>
#define N 1005
using namespace std;
int T,n,a[N],clr[N];
int dfs(int x){
    int val=0;
    for(int i=x-1;i>=1;i--){
        if(clr[i]==clr[x]){
            if(a[i]==a[x])
                val+=a[i];

            break;
        }
    }
    if(x==n)
        return val;

    int way1,way2;
    clr[x+1]=0;
    way1=dfs(x+1);
    clr[x+1]=1;
    way2=dfs(x+1);
    return val+max(way1,way2);
}
void solve(){
    memset(a,0,sizeof(a));
    memset(clr,0,sizeof(clr));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",dfs(1));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
