#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);}
const int INF=100'000'000'000'000'000;
const int mod=998244353;
void add(int& x,int y){x=(x+y)%mod;}
void mul(int& x,int y){x=x*y%mod;}
void to_min(int& x,int y){if(x>y) x=y;}
void to_max(int& x,int y){if(x<y) x=y;}
const int N=1000010;
const int L=20;
int n,m,k,_a[N],a[N],c[N],ans[N],lg[N],X[N],v[N],mi[N];
vector<int> d[N],b[N];
string s;
int sum(int l,int r){return (l+r)*(r-l+1)/2;}
pair<int,int> dfs(int i,int u,int t){
    if(!t) return b[t][u]<=i?make_pair(1,b[t][u]):make_pair(0,b[t][u]);
    if(v[t-1]){
        int l=b[t-1][u*2-1];
        if(!d[t][u]){
            if(a[l]>=t) return {1,l};
            else return dfs(i,u*2,t-1);
        }
        else{
            auto ret=dfs(i,u*2,t-1);
            if(ret.first==1) return a[ret.second]>=t?ret:make_pair(1ll,l);
            return {0,ret.second+(a[l]>=lg[i]+1?l:0)};
        }
    }
    auto ret=dfs(i,u*2-1,t-1);
    int r=sum((u-1)*(1<<t)+1,u*(1<<t));
    if(!d[t][u]){
        if(ret.first==1) return ret.second>=t?ret:make_pair(0ll,r);
        else return {0,ret.second+r};
    }
    return {0,ret.second+r};
}
void solve(){
    //cout<<"?"<<endl;
    for(int i=1;i<=k;i++) for(int j=1;j<=1<<k-i;j++){
        b[i][j]=b[i-1][j*2-(d[i][j]^(a[b[i-1][j*2+d[i][j]-1]]>=i))];
    }
    for(int i=1;i<=n;i++){
        int t=lg[i];
        for(int j=0;j<=t+1;j++) v[j]=i>>j&1;
        if(mi[i]) ans[i]=b[lg[i]+1][1];
        else
            //ans[i]=dfs(i,1,t+1).second;
            continue;
    }
    int anss=0;
    for(int i=1;i<=m;i++) anss^=i*ans[c[i]];
    //for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    //for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
    cout<<anss<<endl;
}
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    IOS();
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>_a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    for(int i=0;1<<i<=n*2;i++) lg[1<<i]--,mi[1<<i]=1;
    k=lg[n]+1;
    for(int i=1;i<=k;i++){
        d[i].resize((1<<k-i)+1);
        b[i].resize((1<<k-i)+1);
        cin>>s;
        for(int j=0;j<1<<k-i;j++) d[i][j+1]=s[j]-'0';
    }
    b[0].resize((1<<k)+1);
    for(int i=1;i<=1<<k;i++) b[0][i]=i;
    int T;cin>>T;
    while(T--){
        cin>>X[0]>>X[1]>>X[2]>>X[3];
        for(int i=1;i<=n;i++) a[i]=_a[i]^X[i%4];
        solve();
    }
}
//Distorted Fate