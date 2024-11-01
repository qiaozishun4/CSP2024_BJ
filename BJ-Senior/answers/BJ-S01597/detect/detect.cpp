#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
int T,n,m,lm,vm,a1,a2,p[N],v[N],a[N],x[N],c[N],l[N],r[N];
int t[N],ta;
inline void add(int x,int v){
    while(x<=m) t[x]+=v,x+=(x&-x);
}
inline int ask(int x){
    ta=0;
    while(x) ta+=t[x],x^=(x&-x);
    return ta;
}
vector<pair<int,int> > vv;
vector<int> vis;
inline bool chk(int v,int a,int s){
    return (vm-v)*(vm+v)<2*a*s;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>lm>>vm;
        for(int i=1;i<=n;++i) cin>>p[i]>>v[i]>>a[i];
        for(int i=1;i<=m;++i) cin>>x[i];
        memset(c,0,sizeof c);
        for(int i=1,tp,pp;i<=n;++i){
            if(p[i]>x[m]) continue;
            pp=lower_bound(x+1,x+m+1,p[i])-x;
            if(a[i]>=0){
                if(v[i]>vm){
                    c[i]=1;
                    l[i]=pp,r[i]=m;
                    continue;
                }
                tp=x[m];
                if(a[i]==0) continue;
                if(chk(v[i],a[i],tp-p[i])){
                    c[i]=1;
                    int ll=pp,rr=m,mid,ans=m;
                    while(ll<=rr){
                        mid=(ll+rr)>>1;
                        if(chk(v[i],a[i],x[mid]-p[i])) rr=mid-1,ans=mid;
                        else ll=mid+1;
                    }
                    l[i]=ans,r[i]=m;
                }
            }else{
                if(v[i]<=vm) continue;
                tp=x[pp];
                if(chk(v[i],a[i],tp-p[i])){
                    c[i]=1;
                    int ll=pp,rr=m,mid,ans=-1;
                    while(ll<=rr){
                        mid=(ll+rr)>>1;
                        if(chk(v[i],a[i],x[mid]-p[i])) ll=mid+1,ans=mid;
                        else rr=mid-1;
                    }
                    l[i]=pp,r[i]=ans;
                }
            }
        }
        a1=a2=0;
        for(int i=1;i<=n;++i) a1+=c[i];
        vv.clear();
        for(int i=1;i<=m;++i) if(c[i]) vv.push_back(make_pair(l[i],r[i]));
        sort(vv.begin(),vv.end(),[&](const pair<int,int> &a,const pair<int,int> &b){return a.first==b.first?a.second>b.second:a.first<b.first;});
        vis.resize(vv.size());
        for(int i=0;i<vis.size();++i) vis[i]=0;
        for(int i=vv.size()-1,mr=1e9;i>=0;--i){
            //printf("[%d,%d] mr=%d\n",vv[i].first,vv[i].second,mr);
            if(vv[i].second>=mr) vis[i]=1;
            mr=min(mr,vv[i].second);
        }
        memset(t,0,sizeof t);
        for(int i=0;i<vv.size();++i){
            //printf("[%d,%d] vis=%d\n",vv[i].first,vv[i].second,vis[i]);
            if(vis[i]) continue;
            if(ask(vv[i].second)!=ask(vv[i].first-1)) continue;
            a2++;
            add(vv[i].second,1);
        }
        cout<<a1<<' '<<m-a2<<'\n';
    }
}
