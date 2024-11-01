#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+15;
const int MAXM=1e6+5;
ll a[MAXN],b[MAXN],lastt[MAXM],dp[MAXM];
ll tot;
struct node{
    ll l,r,val;
}q[MAXN];
bool cmp(node x,node y){
    if(x.r==y.r) return x.l<y.l;
    return x.r<y.r;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll T;
    cin>>T;
    while(T--){
        memset(lastt,0,sizeof(lastt));
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        memset(q,0,sizeof(q));
        tot=0;
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;i++)   cin>>a[i];
        for(int i=1;i<=n;i++){
            if(lastt[a[i]]){
                if(lastt[a[i]]==i-1) ans+=a[i];
                else{
                    q[++tot].l=lastt[a[i]]+1;
                    q[tot].r=i-1;
                    q[tot].val=a[i];
                }
            }
            lastt[a[i]]=i;
        }
        sort(q+1,q+tot+1,cmp);
        ll noww=1;
        for(int i=1;i<=MAXM;i++){
            dp[i]=dp[i-1];
            while(q[noww].r==i){
                dp[i]=max(dp[i],q[noww].val+dp[q[noww].l-1]);
                noww++;
            }
        }
        cout<<ans+dp[MAXM]<<endl;
    }
    return 0;
}
