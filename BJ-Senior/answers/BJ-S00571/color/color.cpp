#include<iostream>
#include<map>
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((l+r)>>1)
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(l);i>=(r);i--)
using namespace std;
const int maxn=2e5+5,maxv=1e6+5;
typedef long long ll;
ll a1[maxn];
int lnk[maxv],pre[maxv];
bool vis[maxv];
typedef pair<int,int> pr;
map<pr,ll> mp;
struct Segment{
    ll as[maxn<<2],col[maxn<<2];
    void build(int l,int r,int x){
        as[x]=col[x]=0;
        if(l==r){
            return;
        }
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
    inline void pushup(int x){
        as[x]=max(as[lson],as[rson]);
    }
    inline void color(int x,ll v){
        col[x]+=v;
        as[x]+=v;
    }
    inline void pushcol(int x){
        if(col[x]){
            color(lson,col[x]);
            color(rson,col[x]);
            col[x]=0;
        }
    }
    void add(int l,int r,int x,int ql,int qr,ll v){
        if(l>=ql&&r<=qr){
            color(x,v);
            return;
        }
        pushcol(x);
        if(ql<=mid)add(l,mid,lson,ql,qr,v);
        if(qr>mid)add(mid+1,r,rson,ql,qr,v);
        pushup(x);
    }
    ll query(int l,int r,int x,int ql,int qr){
        if(l>=ql&&r<=qr)return as[x];
        ll res=0;
        pushcol(x);
        if(ql<=mid)res=max(res,query(l,mid,lson,ql,qr));
        if(qr>mid)res=max(res,query(mid+1,r,rson,ql,qr));
        pushup(x);
        return res;
    }
}st;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int it;
    cin>>it;
    while(it--){
        int in;
        cin>>in;
        // printf("%d\n",in);
        // if(in>3000)break;
        rep(v1,1,in){
            scanf("%lld",a1+v1);
            pre[v1]=lnk[a1[v1]]=0;
            // if(v1>1)sum[v1]=sum[v1-1]+(a1[v1-1]==a1[v1]?a1[v1]:0);
            // // cout<<v1<<' '<<sum[v1]<<endl;
            // av[a1[v1]]=0;
            // vis[a1[v1]]=false;
        }
        st.build(1,in,1);
        rep(v1,1,in){
            pre[v1]=lnk[a1[v1]];
            lnk[a1[v1]]=v1;
            int cur=pre[v1];
            ll nv=0;
            if(v1>1){
                nv=st.query(1,in,1,1,v1-1);
                if(cur&&cur<v1-1)nv=max(nv,st.query(1,in,1,cur+1,cur+1)+a1[v1]);
                st.add(1,in,1,v1,v1,nv);
            }
            if(v1>1&&pre[v1]==v1-1){
                st.add(1,in,1,1,v1-1,a1[v1]);
            }
            // if(v1>1){
            //     int lst=v1-1;
            //     cur=pre[v1-1];
            //     while(cur){
            //         if(st.query(1,in,1,cur+1,cur+1)<=nv)pre[lst]=pre[cur],cur=lst;
            //         else break;
            //         lst=cur;
            //         cur=pre[cur];
            //     }
            // }
        }
        // av[0]=0;
        // rep(v1,1,in){
        //     dp[v1]=dp[v1-1]+sum[v1]-sum[v1-1];
        //     if(vis[a1[v1]])dp[v1]=max(dp[v1],sum[v1-1]+av[a1[v1]]+a1[v1]);
        //     av[a1[v1]]=max(av[a1[v1]],dp[v1]-sum[v1+1]);
        //     vis[a1[v1]]=true;
        //     cout<<v1<<' '<<dp[v1]<<endl;
        // }
        printf("%lld\n",st.query(1,in,1,1,in));
        // break;
    }
    return 0;
}