//check your memory consumption
#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int N=200100,M=1000010;
inline int read(){
    int i=getchar(),r=0;
    while(i<'0'||i>'9')i=getchar();
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r;
}
int n,a[N],sum[N];
inline int w(int x,int y){return x==y?x:0;}
int f[N],mx[M];
void solve(){
    memset(f,0,sizeof(f));
    memset(mx,0xc0,sizeof(mx));
    mx[0]=0;
    for(int i=2;i<=n;i++){
        f[i]=max(mx[0]+sum[i-1],mx[a[i]]+sum[i-1]+a[i]);
        mx[0]=max(mx[0],f[i]-sum[i]);
        mx[a[i-1]]=max(mx[a[i-1]],f[i]-sum[i]);
    }
    int ans=0;
    for(int j=1;j<=n;j++)ans=max(ans,f[j]+sum[n]-sum[j]);
    cout<<ans<<endl;
}
inline void init(){
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+w(a[i-1],a[i]);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;cin>>T;
    while(T--){
        init();
        solve();
    }
    fflush(stdout);
    fflush(stdin);
    fclose(stdin);
    fclose(stdout);
    return 0;
}