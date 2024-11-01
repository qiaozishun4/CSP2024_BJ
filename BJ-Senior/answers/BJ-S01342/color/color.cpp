#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int T,n,ans,a[maxn];
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;i++)
            for (int j=i-1;j>=1;j--)
                if (a[i]==a[j]) {
                    ans+=a[i];
                    break;
                }
        printf("%d\n",ans);
    }
    return 0;
}
