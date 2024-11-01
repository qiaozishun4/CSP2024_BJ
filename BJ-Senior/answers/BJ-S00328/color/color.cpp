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
int dp[2005],g[2005],a[2005],val[2005][2005];//dp[i][0] makes it red.  dp[i][1] makes it blue.
vector<int>v[2005];
inline int calc(int l,int r){
    int ans=0;
    bool f=0;
    for(int i=r-1;i-1>=l;i--){
        if(a[i]==a[i-1]&&!f) ans+=a[i-1];
        f^=1;
    }
    return ans;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    read(t);
    while(t--){
        int n;
        read(n);
        rep(i,0,2000) v[i].clear();
        memset(dp,0,sizeof(dp));
        memset(g,0,sizeof(g));
        rep(i,1,n) read(a[i]),v[a[i]].push_back(i);
        for(int j=n;j>=1;j--){
            bool f=0;
            int ans=0;
            for(int i=j-1;i>=1;i--){
                if(a[i]==a[i-1]&&!f) ans+=a[i-1],val[j][i]=ans;
                f^=1;
            }
        }
        rep(i,1,n){
            for(int j:v[a[i]]){
                if(j>=i) break;
                dp[i]=g[j]+val[j][i]+a[j];
                g[i]=max(g[i],dp[i]);
            }
        }
        /*rep(i,1,n){
            for(int j:v[a[i]]){
                dp[i][j]=g[j]+calc(j,i);
                g[i]=max(g[i],dp[i][j]);
            }
        }*/

        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=g[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
