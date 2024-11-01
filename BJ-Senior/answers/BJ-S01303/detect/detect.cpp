#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int MXN=1e5+10,MXM=1e5+10,MXL=1e6+10;
const double eps=1e-9;
int T;
int n,m,L,V;
int d[MXN],v[MXN],a[MXN];
int p[MXM];
int cnt[MXL],dis[MXL];
pii q[MXN];
int id[MXL],lcnt=0;
vector<int> e[MXL];
inline int up(const double ln){
    if(ln>L+2) return L+2;
    return (int)(ln+eps)+1;
}
inline int down(const double ln){
    if(ln>L+2) return L+2;
    return (int)(ln-eps);
}
pii get_p(const int i){
    int l=-1,r=-1;
    if(a[i]==0){
        if(v[i]>V){
            l=d[i],r=L;
        }
    }else if(a[i]<0){
        if(v[i]>V){
            double ln1=v[i],ln2=V,ln3=a[i],ls;
            ls=(ln2*ln2-ln1*ln1)/(2*ln3);
            l=d[i],r=min(d[i]+down(ls),L);
        }
    }else if(a[i]>0){
        if(v[i]>V){
            l=d[i],r=L;
        }else{
            double ln1=v[i],ln2=V,ln3=a[i],ls;
            ls=(ln2*ln2-ln1*ln1)/(2*ln3);
            l=d[i]+up(ls),r=L;
            if(l>r) l=-1,r=-1;
        }
    }
    return make_pair(l,r);
}
inline bool check(const pii lp){
    if(lp.first<0) return 0;
    if(lp.first==0) return cnt[lp.second]>0;
    return cnt[lp.second]-cnt[lp.first-1]>0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        lcnt=0;
        for(int i=0;i<=L+1;i++){
            cnt[i]=0;
            dis[i]=0;
            e[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            q[i]=get_p(i);
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            cnt[p[i]]=1;
        }
        for(int i=1;i<=L+1;i++){
            if(cnt[i-1]==0){
                id[i]=id[i-1];
            }else{
                id[i]=++lcnt;
            }
        }
        for(int i=1;i<=L+1;i++){
            cnt[i]+=cnt[i-1];
        }
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(check(q[i])){
                //cout<<i<<' '<<id[q[i].first]<<' '<<id[q[i].second+1]<<'\n';
                e[id[q[i].first]].push_back(id[q[i].second+1]);
                ans1++;
            }
        }
        for(int i=lcnt;i>=0;i--){
            for(auto v:e[i]){
                dis[i]=min(dis[i],dis[v]-1);
            }
            dis[i]=min(dis[i],dis[i+1]);
        }
        ans2=m-(dis[lcnt]-dis[0]);
        cout<<ans1<<' '<<ans2<<'\n';
    }
    return 0;
}
