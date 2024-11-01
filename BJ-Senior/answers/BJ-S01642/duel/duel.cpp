#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;
#define Set(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define irep(i,x,y) for(int i=y;i>=x;--i)
#define File(str) \
    freopen(str".in","r",stdin);\
    freopen(str".out","w",stdout)
#define Dbg(fmt,...) \
    fprintf(stderr,"[%s:%d %s]" fmt "\n",__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
#define fi first
#define se second
#define pb push_back
const int N=1e5+10;
int n,a[N];
main(){
    File("duel");
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    deque<int> q;
    rep(i,1,n){
        if(!q.size()){
            q.pb(a[i]);
            continue;
        }
        if(q.front()<a[i]) q.pop_front();
        q.pb(a[i]);
    }
    cout<<q.size()<<'\n';
}
