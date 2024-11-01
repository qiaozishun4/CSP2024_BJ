#include<bits/stdc++.h>
using namespace std;
int n,a[100010],c[100010],l,r,m,sum,vis[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i],c[a[i]] += 1,l = min(l,a[i]),m = max(m,a[i]);
    while(r <= m)
    {
        while(!c[l]) l += 1;
        while(!c[r] || r <= l) r += 1;
        int minn = min(c[l],c[r] - vis[r]);
        c[l] -= minn;
        vis[r] += minn;
        if(vis[r] >= c[r]) r += 1;
    }
    for(int i = 1;i <= m;i++) sum += c[i];
    cout << sum << endl;
    return 0;
}
