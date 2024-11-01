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
int n,m,L,V,d[N],v[N],a[N],p[N],cnt,ans,flag,nxt[N];
struct Node{
    int l,r;
    bool operator<(const Node& x)const{
        return l==x.l?r<x.r:l<x.l;
    }
}node[N];
int calc(int i,int x){
    return max(0ll,2*a[i]*(x-d[i])+v[i]*v[i]);
}
void solve(){
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
    for(int i=1;i<=m;i++) cin>>p[i];p[0]=-1ll;
    for(int i=0;i<=L;i++) nxt[i]=0;
    for(int i=1;i<=m;i++) for(int j=p[i-1]+1;j<=p[i];j++) nxt[j]=i;
    cnt=0;ans=0;flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(v[i]>V&&nxt[d[i]]) ans++,node[++cnt]={nxt[d[i]],m};
        }
        else if(a[i]>0){
            if(!nxt[d[i]]||calc(i,p[m])<=V*V) continue;
            ans++;
            int l=nxt[d[i]],r=m;
            while(l<r){
                int mid=l+r>>1;
                if(calc(i,p[mid])>V*V) r=mid;
                else l=mid+1;
            }
            node[++cnt]={l,m};
        }
        else if(a[i]<0){
            int pos=p[nxt[d[i]]];
            if(!nxt[d[i]]||calc(i,pos)<=V*V) continue;
            ans++;
            int l=nxt[d[i]],r=m;
            while(l<r){
                int mid=l+r+1>>1;
                if(calc(i,p[mid])>V*V) l=mid;
                else r=mid-1;
            }
            node[++cnt]={nxt[d[i]],r};
        }
    }
    cout<<ans<<" ";
    sort(node+1,node+cnt+1);
    //for(int i=1;i<=cnt;i++) cout<<node[i].l<<" "<<node[i].r<<endl;
    int cur=node[1].r,ans2=0;
    for(int i=2;i<=cnt;i++){
        if(node[i].l>cur) ans2++,cur=node[i].r;
        else to_min(cur,node[i].r);
    }
    cout<<m-ans2-(ans!=0)<<endl;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    IOS();
    int T;cin>>T;
    while(T--) solve();
}
