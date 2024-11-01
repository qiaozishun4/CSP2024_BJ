#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;
#define pb push_back
#define fi first
#define se second
#define TLC (double)clock()/CLOCKS_PER_SEC<0.91
const int N=1e5+10,P=1e9+7;
#define File(str) \
    freopen(str".in","r",stdin);\
    freopen(str".out","w",stdout)
#define Dbg(fmt,...)\
    fprintf(stderr,"[%s:%d %s]:" fmt "\n",__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
int Ceil(int x,int y){
    return (x+y-1)/y;
}
int dep,ch;
const pair<int,int> tbl[]={{0,6},{1,2},{2,5},{4,4},{6,6},{7,3},{8,7}};//7
void dfs(int d,int lft,int now,int lim){
    if(lft<0)return;
    if(d==dep+1){
        if(!lft)ch=min(ch,now);
        return;
    }
    if(d==1){
        for(int i=1;i<7;++i)
            dfs(d+1,lft-tbl[i].se,now*10+tbl[i].fi,0);
        return;
    }
    for(int j=lim;j<7;++j)
        dfs(d+1,lft-tbl[j].se,now*10+tbl[j].fi,j);
}
void Solve(){
    int n,k;
    cin>>n;
    int len=Ceil(n,7);
    k=len;
    while(k&&Ceil(n-7*(k-1),6)==len-(k-1))
        --k;
    dep=len-k,ch=1e18;
    dfs(1,n-7*k,0,0);
    if(ch==1e18){
        cout<<"-1\n";
        return;
    }
    vector<int> res;
    int tmp=ch;
    while(tmp){
        res.push_back(tmp%10);
        tmp/=10;
    }
    while(k--) res.pb(8);
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();++i){
        if(res[i]) {
            swap(res[0],res[i]);
            break;
        }
    }
    if(!res[0]){
        cout<<"-1\n";
        return;
    }
    for(int x:res)cout<<x;
    cout<<'\n';
}
signed main(){
    File("sticks");
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)Solve();
    return 0;
}

