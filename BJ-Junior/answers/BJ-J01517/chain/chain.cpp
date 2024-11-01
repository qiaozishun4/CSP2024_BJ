#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,q;
int a[N],len[N],r,c;
bool flag,vis[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&k,&q);
        memset(vis,0,sizeof(vis));
        flag = false;
        for(int i=1;i<=n;i++){
            scanf("%d",&len[i]);
            for(int j=1;j<=len[i];j++){
                scanf("%d",&a[j]);
                vis[a[j]] = true;
            }
        }
        while(q--){
            scanf("%d %d",&r,&c);
            if(!vis[c]){
                printf("0\n");
                continue;
            }
            printf("0\n");
        }
    }
    return 0;
}
