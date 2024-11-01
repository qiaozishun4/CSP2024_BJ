#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,die,cnt,last,mon[maxn];
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&mon[i]);
    sort(mon+1,mon+n+1);
    cnt=1;
    for (int i=2;i<=n;i++) {
        if (mon[i]==mon[i-1])
            cnt++;
        else {
            if (last==0)
                last=cnt;
            else {
                die+=min(last,cnt);
                last=max(0,last-cnt)+cnt;
            }
            cnt=1;
        }
    }
    die+=min(last,cnt);
    printf("%d",n-die);
    return 0;
}
