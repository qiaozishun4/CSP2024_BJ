#include<iostream>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
using namespace std;
const int maxn=2e5+5,maxk=20;
typedef long long ll;
const ll P=2147483647;
int dp[maxk][maxn<<1];
ll ab[maxn],a1[maxn],sum[maxn<<1],s2[maxn<<1],st[maxn<<1];
int ac[maxn],ak[maxn],K;
void modify(int pos,ll v){
    for(int v1=pos;v1<=K;v1+=v1&(-v1))st[v1]+=v;
}
ll query(int pos){
    ll res=0;
    for(int v1=pos;v1;v1-=v1&(-v1))res+=st[v1];
    return res;
}
int read(){
    char c=getchar();
    while(c<'0'||c>'1')c=getchar();
    return c-'0';
}
int ax[5];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int in,im,it,ik=0;
    cin>>in>>im;
    while((1<<ik)<in)ik++;
    K=1<<ik;
    rep(v1,1,in)scanf("%lld",ab+v1);
    rep(v1,1,im){
        scanf("%d",ac+v1);
        while((1<<ak[v1])<ac[v1])ak[v1]++;
        ak[v1]=(1<<ak[v1]);
    }
    int tmp=K;
    rep(v1,1,ik){
        tmp>>=1;
        rep(v2,1,tmp){
            // cout<<v1<<' '<<v2<<' '<<(v2<<1|(read()))<<endl;
            dp[v1][(v2<<1|(read()))-1]=v1;
        }
    }
    // per(v1,ik,1){
    //     rep(v2,1,1<<(ik-v1+1))cout<<dp[v1][v2]<<' ';
    //     cout<<endl;
    // }
    // cout<<"zs"<<endl;
    per(v1,ik-1,1)rep(v2,1,1<<(ik-v1+1)){
        // cout<<v1<<' '<<v2<<' '<<(v2-1>>1)+1<<' '<<dp[v1+1][(v2-1>>1)+1]<<' '<<max(dp[v1][v2],dp[v1+1][(v2-1>>1)+1])<<endl;
        dp[v1][v2]=max(dp[v1][v2],dp[v1+1][(v2-1>>1)+1]);
    }
    scanf("%d",&it);
    while(it--){
        rep(v1,0,3)scanf("%d",ax+v1);
        rep(v1,1,in)sum[v1]=sum[v1-1]+((a1[v1]^ax[v1%4])>=dp[1][v1]?v1:0);
        rep(v1,1,K)s2[v1]=s2[v1-1]+v1;
        ll ans=0;
        rep(v1,1,im){
            // cout<<v1<<' '<<ac[v1]<<' '<<ak[v1]<<' '<<sum[ac[v1]]+s2[ak[v1]]-s2[ac[v1]]<<endl;
            ans^=ll(v1)*(sum[ac[v1]]+s2[ak[v1]]-s2[ac[v1]]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}