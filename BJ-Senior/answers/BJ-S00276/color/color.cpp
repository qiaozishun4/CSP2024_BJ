#include <iostream>
using namespace std;

const int N = 2e5 + 5,A = 1e6 + 5;

int T,n;
long long a[N],dp[2][N];
int box[A];
int pre[N],nxt[N];
long long ans;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 1;i <= A - 5;i++){
            box[i] = 0;
        }
        ans = 0;
        for(int i = 1;i <= n;i++){
            dp[0][i] = dp[1][i] = nxt[i] = pre[i] = 0;
            scanf("%lld",&a[i]);
            if(a[i] == a[i - 1]) ans += a[i];
            if(box[a[i]]){
                pre[i] = box[a[i]];
                nxt[box[a[i]]] = i;
                box[a[i]] = i;
            }else{
                box[a[i]] = i;
            }
        }
        for(int i = 1;i <= n;i++){
            dp[0][i + 1] = max(dp[0][i + 1],max(dp[0][i],dp[1][i]));
            if(nxt[i] && nxt[i] != i + 1) dp[1][nxt[i]] = max(dp[1][nxt[i]],max(dp[0][i],dp[1][i]) + a[i]);
            if(nxt[i - 1] && nxt[i - 1] != i) dp[1][nxt[i - 1]] = max(dp[1][nxt[i - 1]],max(dp[0][i],dp[1][i]) + a[i - 1]);
        }

        printf("%lld\n",ans + max(dp[1][n],dp[0][n]));
    }
}