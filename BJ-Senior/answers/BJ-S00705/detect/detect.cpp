#include<bits/stdc++.h>
#define ll long long
#define N 500050
using namespace std;
ll n,ans,t,m,l,V,p[N],q[N*2];
struct e{
    ll l,r,val;
}tr[N*2];
pair<ll,ll> f[N];
bool cmp(ll x,ll y){
    return x<y;
}
void build(ll k,ll l,ll r){
    if(l==r){
        for(int i=1;i<=m;i++){
            if(p[i]==l){
                tr[k].val=1;
                break;
            }
        }
        return ;
    }

    ll mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tr[k].l=l;
    tr[k].r=r;
    tr[k].val=tr[k<<1].val+tr[k<<1|1].val;
}
ll find(ll k,ll l,ll r){
    if(tr[k].l>=l&&tr[k].r<=r){
        return tr[k].val;
    }
    ll mid=(l+r)>>1;ll re=0;
    if(mid>=l)re+=find(k<<1,l,r);
    if(mid<r)re+=find(k<<1|1,l,r);

    return re;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t>0){
        t--;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            if(z!=0){
                ll k=(V*V-y*y)/(2*z);
            if(y>=V){
                f[i]={x,x+k};
            }else{
                f[i]={x+k,l};
            }

            }else{
                if(y>V){
                f[i]={x,l};
            }else{
                f[i]={0,0};
            }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        //cout<<114514;
        build(1,1,n);
        //cout<<21434356;
        for(int i=1;i<=n;i++){
            if(find(1,f[i].first,f[i].second)>0){
                ans++;
            }
        }
        cout<<ans<<" ";

    }
    return 0;
}
