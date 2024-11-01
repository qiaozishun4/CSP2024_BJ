#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
int a[200300];
int n;
// int w[1000300<<2];
// int tg[1003000<<2];
// #define lc(x) (x<<1)
// #define rc(x) (x<<1|1)
// inline void upd(int x){
//     w[x]=max(w[lc(x)],w[rc(x)]);
// }
// inline void pd(int x){
//     if(tg[x]){
//         w[lc(x)]+=tg[x];
//         w[rc(x)]+=tg[x];
//         tg[lc(x)]+=tg[x];
//         tg[rc(x)]+=tg[x];
//         tg[x]=0;
//     }

// }
// inline void bd(int x,int l,int r){
//     tg[x]=0;
//     if(l==r){
//         if(l==0)w[x]=0;
//         else w[x]=-1e18;
//     }
//     int mid=l+r>>1;
//     bd(lc(x),l,mid);
//     bd(rc(x),mid+1,r);
// }
// inline void mod(int x,int l,int r,int L,int R,int k){
//     if(L<=l&&r<=R){
//         tg[x]+=k;
//         return ;
//     }
// }
int f[1000300];
int tg=0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(f,-0x3f,sizeof(f));
        f[0]=0;
        int mx=0;
        int tg=0;
        for(int i=1;i<=n;i++){
            int p=a[i-1],x=a[i];
            int w=max(f[x]+x+tg,mx);
            
            if(p==x){
                tg+=x;
                mx+=x;
            }
            if(w>f[p]+tg){
                // cout<<i<<" "<<p<<" "<<x<<" "<<w<<" "<<tg<<" "<<f[x]<<" "<<endl;;
                f[p]=w-tg;
                mx=max(mx,w);
            }
            // cout<<i<<" "<<a[i]<<" "<<w<<" "<<tg<<endl;
            // for(int i=1;i<=15;i++)
            // cout<<f[i]+tg<<" ";
            // cout<<endl;
        }
        cout<<mx<<endl;
    }

    cout.flush();
    fflush(stdout);
    fclose(stdout);
    return 0;
}