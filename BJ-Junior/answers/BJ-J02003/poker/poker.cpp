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
int n; string s;
map<string,bool> vis;
const char *a="DCHS",*b="A23456789TJQK";
signed main(){
    File("poker");
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    while(n--){
        cin>>s;
        vis[s]=1;
    }
    int ans=0;
    for(int i=0;i<4;++i)
    for(int j=0;j<13;++j){
        string s; s+=a[i],s+=b[j];
        if(!vis[s])++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
