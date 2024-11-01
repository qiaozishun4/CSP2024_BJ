#include<bits/stdc++.h>
#define ll long long
#define lson pos<<1
#define rson pos<<1|1
using namespace std;
const int maxn=1e5+10;
const ll mod=998244353;
const ll inf=1e9+10;
ll n,m,t,l,ans;
double v;
ll color[maxn],a[maxn];

struct node{
    double d,v,a;
}q[maxn];

struct line{
    int id,checker,opt;
}p[maxn*2];

inline void dfs(int dep){
    if(!dep){
        int lstr=0,lstb=0;
        ll tmp=0;
        for(int i=1;i<=n;i++){
            if(color[i]==1){
                if(a[lstr]==a[i]) tmp+=a[i];
                lstr=i;
            }
            else{
                if(a[lstb]==a[i]) tmp+=a[i];
                lstb=i;
            }
        }
        ans=max(ans,tmp);
        return;
    }

    color[n-dep+1]=1;
    dfs(dep-1);
    color[n-dep+1]=2;
    dfs(dep-1);
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);

    while(t--){
        scanf("%lld",&n);

        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        ans=0;

        if(n<=20){
            dfs(n);
            printf("%lld\n",ans);
        }
    }

   fclose(stdin);
    fclose(stdout);
    return 0;
}
