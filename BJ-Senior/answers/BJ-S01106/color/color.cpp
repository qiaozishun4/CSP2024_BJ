#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int a,b;
};
const int N=2e5+5;
int a[N];
node b[N];
int dp[N];
int s[N];
int l[N];
int n;
int ans;
int f(int x,int y){
    if(x==y){
        return x;
    }
    return 0;
}
bool cmp(node x,node y){
    if(x.a!=y.a)return x.a<y.a;
    return x.b<y.b;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        memset(a,0,sizeof a);
        memset(dp,0,sizeof dp);
        memset(s,0,sizeof s);
        memset(l,0,sizeof l);
        memset(b,0,sizeof b);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i].a=a[i];
            b[i].b=i;
            if(i==1){
                s[i]=0;
            }
            else{
                s[i]=s[i-1]+f(a[i],a[i-1]);
            }
        }
        sort(b+1,b+n+1,cmp);
        for(int i=2;i<=n;i++){
            if(b[i].a!=b[i-1].a)continue;
            l[b[i].b]=b[i-1].b;
        }
        for(int i=2;i<=n;i++){
            if(l[i]>0)dp[i]=max(dp[i-1]+f(a[i-1],a[i]),dp[l[i]+1]+s[i-1]-s[l[i]+1]+a[i]);
            else dp[i]=dp[i-1]+f(a[i-1],a[i]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
