#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50,INF = 0x3f3f3f3f;
int n;
int r[maxn];
int cnt[maxn],maxx = -INF;
int pre[maxn];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int x;
    pre[0] = 0;
    memset(r,0,sizeof(r));
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&r[i]);
        cnt[r[i]]++;
        maxx = max(maxx,r[i]);
    }
    for(int i = 1;i <= maxx;i++)pre[i] = pre[i - 1] + cnt[i];
    for(int i = 1;i <= maxx;i++){
        if(cnt[i] <= (n - pre[i]))cnt[i] = 0;
        else {
            cnt[i] = cnt[i] - (n - pre[i]);
            x = i;
            break;
        }
    }
    int ans = 0;
    for(int i = 1;i <= maxx;i++)ans += cnt[i];
    printf("%d",ans);
    return 0;
}
