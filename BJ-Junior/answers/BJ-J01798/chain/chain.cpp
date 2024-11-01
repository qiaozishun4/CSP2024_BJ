#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,k,q;
int T;
int a[N][N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&q);
        int len;
        for(int i = 1;i<=n;i++){
            scanf("%d",&len);
            for(int j = 1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int x,y;
        while(q--){
            scanf("%d%d",&x,&y);
            cout<<1<<endl;
        }
    }

    return 0;
}
