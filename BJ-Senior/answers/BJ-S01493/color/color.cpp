#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int lz[800010],n;
int mx[800010];
#define ls p<<1
#define rs (p<<1)|1
void pushdown(int p){
    lz[ls]+=lz[p];
    lz[rs]+=lz[p];
    mx[ls]+=lz[p];
    mx[rs]+=lz[p];
    lz[p]=0;
}
void updv(int p,int l,int r,int L,int R,int v){
    if(L<=l&&r<=R){
        lz[p]+=v;
        mx[p]+=v;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p);
    if(mid>=L&&R>=l)updv(ls,l,mid,L,R,v);
    if(r>=L&&R>=mid+1)updv(rs,mid+1,r,L,R,v);
    mx[p]=max(mx[ls],mx[rs]);
}

int getv(int p,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        return mx[p];
    }
    if(r<L||R<l)return -0x4f3f3f3f3f3f3f3f3fll;
    int mid=(l+r)>>1;
    pushdown(p);
    int ans=-0x4f3f3f3f3f3f3f3f3fll;
    if(mid>=L&&R>=l)ans=max(ans,getv(ls,l,mid,L,R));
    if(r>=L&&R>=mid+1)ans=max(ans,getv(rs,mid+1,r,L,R));
    return ans;
}

void cg(int p,int l,int r,int pos,int v){
    if(l==r){
        mx[p]=v;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(p);
    if(pos<=mid)cg(ls,l,mid,pos,v);
    else cg(rs,mid+1,r,pos,v);
    mx[p]=max(mx[ls],mx[rs]);
}

inline void changev(int p,int v2){
    p++;
   cg(1,1,n,p,v2);
}

int mp[200010];
int lastp[1000010],pos[1000010];
inline void upd(int &a,int b){
    a=max(a,b);
}
inline int get(int a,int b){
    if(mp[a]==mp[b])return mp[a];
    return 0;
}
inline int c(int b){
    return b&1;
}
inline int gett(int p){
    return getv(1,1,n,p+1,p+1);
}
inline int getlr(int l,int r){
    return getv(1,1,n,l+1,r+1);
}
inline int updd(int l,int r,int p){
    updv(1,1,n,l+1,r+1,p);
}
int dp[200010];

inline void run(){
    memset(lz,0,sizeof lz);
    memset(mx,0,sizeof mx);
    cin >> n;
    fr(i,1,n)cin >> mp[i];
    int all=0;
    fr(i,1,n){
        lastp[i]=pos[mp[i]];
        pos[mp[i]]=i;
    }
    memset(dp,0,sizeof dp);
    all-=0x3f3f3f3f3f3f3f3fll;
    dp[0]=0x3f3f3f3f3f3f3f3fll;
    changev(0,0x3f3f3f3f3f3f3f3fll);
    fr(i,1,n-1){
        if(get(i,i+1)!=0){
            int k=lastp[i+1];
            if(k==0){
                int mx=getlr(0,i-1)+all;
                all+=get(i,i+1);
                if(dp[i]+all<mx){
                        dp[i]=mx-all;
                        changev(i,dp[i]);
                }
            }
            else{
                int mx=getlr(0,i-1)+all;
                int tmp=dp[k]+all;
                all+=get(i,i+1);
               // cout << i << endl;
                if(dp[i]+all<max(mx,tmp+get(k,i+1))){
                    dp[i]=max(mx,tmp+get(k,i+1))-all;
                }
            }
        }
        else{
            int mx=getlr(0,i-1)+all;
            int k=lastp[i+1];
            if(k==0){
                //cout << dp[i]+all << " " << mx << endl;
                if(dp[i]+all<mx){
                    dp[i]=mx-all;
                    changev(i,dp[i]);
                }
            }
            else {
                if(dp[i]+all<max(mx,dp[k]+all+get(k,i+1))){
                    //    cout << mx << " " <<  dp[k]+get(k,i+1) << endl;
                    dp[i]=max(mx,dp[k]+all+get(k,i+1))-all;
                    changev(i,dp[i]);
                }
            }
        }
      //   fr(i,0,n-1)cout << dp[i]+all << " ";
      //  cout << endl;
    }
    int ans=0;
    fr(i,0,n-1)ans=max(ans,dp[i]+all);
    cout << ans << endl;
   // cout << "--------------------------\n";
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
   // n=100;
   // updv(1,10,10);
   // fr(i,1,20)cout << getv(i) << " ";
    //cout << endl;

    int T;
    cin >> T;
    while(T--){
        run();
    }
return 0;
}
