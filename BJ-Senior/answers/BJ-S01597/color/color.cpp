#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define int long long
int T,nn,aa[N],n,o[N],ans;
int mx[N<<2];
vector<int> u;
int qry(int p,int l,int r,int x){
    if(l==r){return mx[p];}
    int mid=(l+r)>>1;
    if(x<=mid) return qry(p<<1,l,mid,x);
    else return qry(p<<1|1,mid+1,r,x);
}
void mdf(int p,int l,int r,int x,int v){
    if(l==r){mx[p]=v;return;}
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1,l,mid,x,v);
    else mdf(p<<1|1,mid+1,r,x,v);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
    return;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>nn;
        for(int i=1;i<=nn;++i) cin>>aa[i];
        n=ans=0;
        u.clear();
        for(int i=1;i<=nn;++i){
            if(aa[i]==aa[i-1]) ans+=aa[i];
            else o[++n]=aa[i],u.push_back(aa[i]);
        }
        if(n==1){
            cout<<ans<<'\n';
            continue;
        }
        sort(u.begin(),u.end());
        u.erase(unique(u.begin(),u.end()),u.end());
        for(int i=1;i<=n;++i) o[i]=lower_bound(u.begin(),u.end(),o[i])-u.begin();
        memset(mx,-0x3f,sizeof mx);
        for(int i=2,v;i<=n;++i){
            v=max(0ll,max(mx[1],qry(1,0,(int)u.size()-1,o[i])+u[o[i]]));
            mdf(1,0,u.size()-1,o[i-1],v);
        }
        cout<<ans+mx[1]<<'\n';
    }
}
