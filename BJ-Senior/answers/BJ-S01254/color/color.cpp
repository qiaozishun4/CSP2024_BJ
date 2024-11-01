#include<bits/stdc++.h>
#define LL long long
#define CLR(a,x) memset(a,x,sizeof(a))
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int I_INF=2e9+5;
int t,n,a[N];
LL f[2005][2005],val[N],pre[2005][2005],mx[2005];
LL calc(int l,int r) {
    if(a[l]!=a[l-1])return val[r]-val[l-1];
    else return val[r]-val[l-1]-a[l];
}
void solve() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        val[i]=val[i-1]+a[i]*(a[i]==a[i-1]);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=2000;j++)
            if(a[i]==j)pre[i][j]=i;
            else pre[i][j]=pre[i-1][j];
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=i;j++)
            f[i][j]=0;
        mx[i]=0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            int k=i-j,l;
            if(a[k]==a[i-j+1])l=pre[k-1][a[i-j+i]];
            else l=pre[k][a[i-j+1]];
            f[i][j]=max(f[i][j],f[k][k-l]+calc(i-j+1,i)+a[i-j+1]*(l!=0));
            f[i][j]=max(f[i][j],mx[i-j]+calc(i-j+1,i));
        }
        for(int j=1;j<=i;j++)
            mx[i]=max(mx[i],f[i][j]);
    }
    LL ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,f[n][i]);
    printf("%lld\n",ans);
}
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--)
        solve();
    return 0;
}
