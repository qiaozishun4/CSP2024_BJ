#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace FastIO{
    inline int read(){
        int x=0,f=1;
        char ch=getchar();
        while(ch>'9'||ch<'0'){
            if(ch=='-') f=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=(x<<1)+(x<<3)+ch-'0';
            ch=getchar();
        }
        return x*f;
    }
    inline void write(int x){
        if(x<0){
            x=-x;
            putchar('-');
        }
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
using FastIO::read;
using FastIO::write;
const int N=1e6+10;
int n,nn,b[N],a[N],dy[N],cnt,mx[N],vis[N];
void work(){
    n=read();
    cnt=0,nn=0;
    int jia=0;
    for(int i=1;i<N;i++) dy[i]=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(dy[a[i]]==0){
            dy[a[i]]=++cnt;
        }
        if(a[i]!=a[i-1]){
            b[++nn]=a[i];
        }else jia+=a[i];
        mx[i]=0;
        vis[i]=0;
    }
    n=nn;
    for(int i=1;i<=n;i++) a[i]=b[i];
   // cout<<"nn "<<n<<endl;
  //  for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    int qjmax=0;
    for(int i=1;i<=n;i++){
    //    cout<<"i "<<i<<" "<<dy[a[i]]<<" "<<vis[dy[a[i]]]<<endl;
        if(vis[dy[a[i]]]){
            mx[dy[a[i-1]]]=max(mx[dy[a[i-1]]],mx[dy[a[i]]]+a[i]);
            qjmax=max(qjmax,mx[dy[a[i-1]]]);
        }
        mx[dy[a[i-1]]]=max(mx[dy[a[i-1]]],qjmax);
        vis[dy[a[i]]]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,mx[i]);
  //  write(jia);puts("");
    write(ans+jia);puts("");
    return ;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T=read();
    while(T--) work();
    return 0;
}
