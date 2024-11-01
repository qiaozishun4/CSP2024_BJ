#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int r = 1;
    int ans = n;
    for(int l = 1; l <= n; l++){
        while(r <= n && a[r] <= a[l]) r++;
        if(r > n) break;
        ans--,r++;
    }
    printf("%d\n",ans);

    return 0;
}
