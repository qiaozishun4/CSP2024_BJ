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
#define TLC (double)clock()/CLOCKS_PER_SEC<0.91
using db=long double;
const int N=1e5+10,P=1e9+7;
struct node {
    int st,vel,ac;
};
int n,m,L,V,p[N];
vector<node> ap,am;
bool cmp(PII a,PII b){
    if(a.se!=b.se)
        return a.se<b.se;
    return a.fi<b.fi;
}
void Solve(){
    ap.clear();
    am.clear();
    rep(i,1,n)p[i]=0;
    cin>>n>>m>>L>>V;
    rep(i,1,n){
        int d,v,a;
        cin>>d>>v>>a;
        if(a>=0){
            if(v>V)ap.pb({d,v,0});
            else if(a>0)ap.pb({d,v,a});
        }
        else if(v>V)am.pb({d,v,a});
    }
    rep(i,1,m)cin>>p[i];
    //p[++m]=1e18;
    vector<PII> r1;
    int ans1=0;
    for(auto[d,v,a]:am){
        db T=db(V-v)/a;
        db pos=d+v*T+0.5*a*T*T;
        if(pos==floor(pos)) pos=pos-1;
        else pos=floor(pos);
        int itl=lower_bound(p+1,p+m+1,d)-p;
        int itr=lower_bound(p+1,p+m+1,pos+1)-p;
        if(itl<itr) r1.push_back({itl,itr-1}),++ans1;
    }
    for(auto[d,v,a]:ap){
        if(a==0){
            int itl=lower_bound(p+1,p+m+1,d)-p;
            int itr=m+1;
            if(itl<itr) r1.push_back({itl,itr-1}),++ans1;
        }
        else {
            db T=db(V-v)/a;
            db pos=d+v*T+0.5*a*T*T;
            if(pos==ceil(pos)) pos=pos+1;
            else pos=ceil(pos);
            int itl=lower_bound(p+1,p+m+1,pos)-p;
            int itr=m+1;
            if(itl<itr) r1.push_back({itl,itr-1}),++ans1;
        }
    }
    sort(r1.begin(),r1.end(),cmp);
    set<int> s;
    int ans2=0;
    for(auto[l,r]:r1){
        auto it=s.lower_bound(p[l]);
        if(it==s.end()||*it>p[r]) s.insert(p[r]),++ans2;
    }
    cout<<ans1<<' '<<m-ans2<<'\n';
}
main(){
    File("detect");
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
        Solve();
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
