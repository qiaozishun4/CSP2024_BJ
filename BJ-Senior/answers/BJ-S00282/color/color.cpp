#include<bits/stdc++.h>
#define int long long
#define pt printf
#define fr(i,a,b) for(int i(a);i<=b;i++)
#define rf(i,a,b) for(int i(a);i>=b;i--)
#define eb emplace_back
#define pii pair<int,int>
#define file(f1,f2) if(f1!="")freopen(f1,"r",stdin);if(f2!="")freopen(f2,"w",stdout);
using namespace std;
template<typename A,typename...B>inline void rd(A&x,B&...y) {
    cin>>x;
    if constexpr(sizeof...(y))rd(y...);
}
const int N=1e6+33,inf=2e15;
int n,g[N],s[N],a[N],b[N];
signed main() {
    file("color.in","color.out");
    int t;
    rd(t);
    while(t--) {
        rd(n);

        fr(i,0,n)g[i]=s[i]=0;
        fr(i,1,n)rd(a[i]),s[i]=(a[i]==a[i-1])*a[i]+s[i-1],b[a[i]]=-inf;
        if(0&&n<=2000) {
            int ans=0;
            g[1]=0;
            fr(i,2,n) {
                fr(j,1,i-1) {
                    g[i]=max(g[i],g[j]+s[i-1]-s[j]+(a[i]==a[j-1])*a[i]);
                }
                ans=max(ans,g[i]+s[n]-s[i]);
            }

            pt("%d\n",ans);
        }else{
            int ans=0;
            int mx=-inf;
            g[1]=0;
            fr(i,1,n){
                if(i!=1)g[i]=max(mx+s[i-1],b[a[i]]+s[i-1]);
                mx=max(mx,g[i]-s[i]);
                b[a[i-1]]=max(b[a[i-1]],g[i]-s[i]+a[i-1]);
                ans=max(ans,g[i]+s[n]-s[i]);
                //pt("%d:%d\n",i,g[i]);
            }
            pt("%lld\n",ans);
        }

    }


    return 0;
}
