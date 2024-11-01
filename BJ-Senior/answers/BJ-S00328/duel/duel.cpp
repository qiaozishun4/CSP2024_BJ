#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline void read(int &x){
    x=0;bool f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    x=f?x:-x;
}
const int N=1e5+5;
int a[N];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    read(n);
    rep(i,1,n) read(a[i]);
    sort(a+1,a+n+1);
    int l=1,r=1;
    while(r<=n){
        while(a[r]==a[l]&&r<=n) r++;
        if(r>n) break;
        a[l]=-1,l++,r++;
    }
    for(int i=1;i<=n;i++) if(a[i]!=-1) ans++;
    cout<<ans;
    return 0;
}
