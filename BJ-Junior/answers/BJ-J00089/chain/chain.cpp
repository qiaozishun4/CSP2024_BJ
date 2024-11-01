#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N=100005;
int T, n, k, q, l[N], r, c, flag=0;
vector<int> a[N];
void dfs(int last, int depth, int fa){
    if(flag) return;
    if(depth==r){
        if(last==c) flag=1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==fa) continue;
        for(int j=0;j<l[i];j++)
            if(a[i][j]==last)
                for(int ja=j+1;ja<l[i]&&ja-j+1<=k;ja++)
                    dfs(a[i][ja],depth+1,i);
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);
            for(int j=1;j<=l[i];j++){
                int x;
                scanf("%d",&x);
                a[i].push_back(x);
            }
        }
        while(q--){
            scanf("%d%d",&r,&c);
            flag=0;
            dfs(1,0,0);
            printf("%d\n",flag);
        }
    }
    return 0;
}