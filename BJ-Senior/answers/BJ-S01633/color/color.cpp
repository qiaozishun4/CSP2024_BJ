#include <cstdio>
#include <algorithm>
using namespace std;
const long long inf = 1e18;
int t,n,a[200005],mx;
long long f[200005],g[1000005],mxf,sum,ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mx = f[0] = g[0] = mxf = sum = ans = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
            mx = max(mx,a[i]);
            f[i] = -inf;
        }
        for(int i = 1;i <= mx;i++){
            g[i] = -inf;
        }
        for(int i = 1;i <= n;i++){
            f[i - 1] = max(f[i - 1],max(mxf - (a[i - 1] == a[i]) * a[i],g[a[i]] + a[i] - (a[i - 1] == a[i]) * a[i]));
            g[a[i - 1]] = max(g[a[i - 1]],f[i - 1]);
            mxf = max(mxf,f[i - 1]);
            sum += (a[i - 1] == a[i]) * a[i];
        }
        for(int i = 0;i < n;i++){
            ans = max(ans,f[i] + sum);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
