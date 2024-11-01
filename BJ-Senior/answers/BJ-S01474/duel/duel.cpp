#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n, a[MAXN], h[MAXN];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    int ans=n;
    int t=1;
    for(int i=2; i<=n; i++)
    {
        h[i]=h[i-1];
        if(a[i]>a[i-1]) h[i]+=t, t=1;
        else t++;
        if(h[i]) ans--, h[i]--;
    }
    printf("%d", ans);
    return 0;
}
