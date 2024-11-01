#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int l,r,v;
}e[200010];
int t,n,a[200010],b[1000010],dp[200010][2],v[200010];
int cnt;
bool cmp(edge a,edge b){
    return a.r<b.r;
}
int find(int x,int up){
    int l=0,r=up;
    while(l<r){
        int mid=(l+r+1)/2;
        if(e[mid].r<=x)l=mid;
        else r=mid-1;
    }
    return l;
}
void solve(){
    cin>>n;
    cnt=0;
    memset(v,0,sizeof(v));
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(b[a[i]]!=0){
            cnt++;
            e[cnt].l=b[a[i]];
            e[cnt].r=i-1;
            e[cnt].v=a[i];
        }
        b[a[i]]=i;
    }
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        if(e[i].l==e[i].r)v[i]+=e[i].v;
        v[i]+=v[i-1];
    }
    for(int i=1;i<=cnt;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        int p=find(e[i].l,i-1);
        dp[i][1]=max(dp[p][0],dp[p][1])+v[i]-v[p];
        if(e[i].l!=e[i].r)dp[i][1]+=e[i].v;
    }
    cout<<max(dp[cnt][0],dp[cnt][1])<<'\n';
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)solve();
    return 0;
}
