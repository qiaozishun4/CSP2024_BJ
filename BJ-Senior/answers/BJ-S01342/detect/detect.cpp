#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
const int maxL=1e6+5;
int T,n,m,L,V,ans,cnt,detector[maxn],f[maxL];
struct Car {
    int d;
    ll v,a;
}car[maxn];
struct Num {
    ll zheng,fenmu,fenzi;
};
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        ans=0;
        scanf("%d %d %d %d",&n,&m,&L,&V);
        for (int i=1;i<=n;i++)
            scanf("%d %lld %lld",&car[i].d,&car[i].v,&car[i].a);
        memset(f,0,sizeof(f));
        for (int i=1;i<=m;i++) {
            scanf("%d",&detector[i]);
            f[detector[i]]=1;
        }
        for (int i=1;i<=L;i++)
            f[i]+=f[i-1];
        for (int i=1;i<=n;i++) {
            if (car[i].a==0&&car[i].v>V) {
                if (f[L]-f[car[i].d-1]>0)
                    ans++;
            }
        }
        if (ans==0)
            m++;
        printf("%d %d\n",ans,m-1);
    }
    return 0;
}
