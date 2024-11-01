#include<iostream>
#include<vector>
using namespace std;
#define MAXN 200005
int T,n,m,a0[MAXN],a[MAXN],c[MAXN],K,len[25],k0,sum[25][MAXN];
vector<int> d[25],win[25],chkmax[25];
char str[MAXN];
inline bool in(int x,int l,int r){
    return x>=l&&x<=r;
}
void prework(){
    for(int i=n+1;i<=(1<<K);i++) a[i]=-1;
    for(int i=1;i<=(1<<K);i++){
        chkmax[0].push_back(i);
        if(i<=n) win[0].push_back(i);
        else win[0].push_back(-1);
    }
    for(int i=1;i<=K;i++){
        for(int j=0;j<len[i];j++){
            if(d[i][j]==0){
                if(win[i-1][j<<1]==-1){
                    win[i][j]=-1;
                    chkmax[i][j]=chkmax[i-1][j<<1|1];
                }
                else if(a[win[i-1][j<<1]]>=i){
                    win[i][j]=win[i-1][j<<1];
                    chkmax[i][j]=chkmax[i-1][j<<1];
                }
                else{
                    win[i][j]=win[i-1][j<<1|1];
                    chkmax[i][j]=chkmax[i-1][j<<1|1];
                }
            }
            else{
                if(win[i-1][j<<1|1]==-1){
                    win[i][j]=-1;
                    chkmax[i][j]=chkmax[i-1][j<<1|1];
                }
                else if(a[win[i-1][j<<1|1]]>=i){
                    win[i][j]=win[i-1][j<<1|1];
                    chkmax[i][j]=chkmax[i-1][j<<1|1];
                }
                else{
                    win[i][j]=win[i-1][j<<1];
                    chkmax[i][j]=chkmax[i-1][j<<1|1];
                }
            }
        }
    }
}
void init(){
    for(int i=0;i<=K;i++) win[i].clear(),chkmax[i].clear();
    for(int i=1;i<=K;i++){
        cin>>str;
        for(int j=0;j<(1<<(K-i));j++){
            win[i].push_back(0);
            chkmax[i].push_back(0);
        }
    }
}
int work(int nn){
    int ans=0,cur=0;
    for(int i=K;i;i--){
        // cerr<<win[i-1][cur<<1]<<endl;
        if(in(win[i][cur],1,nn)&&in(chkmax[i][cur],1,k0)){
            ans+=win[i][cur];
            break;
        }
        else{
            if(in(win[i-1][cur<<1],1,nn)&&in(chkmax[i-1][cur<<1],1,k0)){
                ans+=win[i-1][cur<<1];
                cur=cur<<1|1;
            }
            else{
                ans+=sum[i-1][cur<<1|1];
                cur=cur<<1;
            }
        }
        // cerr<<cur<<" "<<ans<<endl;
    }
    return ans;
}
void solve(){
    init();
    prework();
    // for(int i=1;i<=K;i++) cout<<a[i]<<" ";cout<<endl;
    int ans=0;
    for(int p=1;p<=m;p++){
        k0=1;
        while(k0<c[p]) k0<<=1;
        ans^=1ll*p*work(c[p]);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a0[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    K=0;
    while((1<<K)<n) K++;
    for(int i=1;i<=(1<<K);i++) sum[0][i]=i;
    for(int i=1;i<=K;i++){
        cin>>str;
        len[i]=(1<<(K-i));
        for(int j=0;j<(1<<(K-i));j++){
            d[i].push_back(str[j]-'0');
            sum[i][j]=sum[i-1][j<<1]+sum[i-1][j<<1|1];
        }
    }
    cin>>T;
    while(T--){
        int X[5];
        cin>>X[0]>>X[1]>>X[2]>>X[3];
        for(int i=1;i<=n;i++) a[i]=a0[i]^X[i%4];
        solve();
    }
    return 0;
}