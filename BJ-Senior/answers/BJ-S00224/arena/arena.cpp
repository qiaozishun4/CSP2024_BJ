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
const int N=2e5+10;
int n,m,a1[N],c[N],a[N],b[N],f[N],d[20][N],do_pre[5],mp[N],yc[N];
int solve(int x){
    for(int i=1;i<=x;i++){
        f[i]=i;
    }
    for(int i=1;i<=log2(x);i++){
        for(int j=1;j<=x/(1<<(i-1));j+=2){
            if(d[i][(j+1)/2]==0){
                if(b[f[j]]>=i) f[(j+1)/2]=f[j];
                else f[(j+1)/2]=f[j+1];
            }else{
                if(b[f[j+1]]>=i) f[(j+1)/2]=f[j+1];
                else f[(j+1)/2]=f[j];
            }
        }
      //  for(int j=1;j<=x/(1<<(i-1));j+=2){
//
     // /      cout<<f[(j+1)/2]<<" ";
//
      //  }cout<<endl;
    }
    return f[1];
}
void dfs(int x,int y){
    if(x>y){
          //  for(int i=1;i<=y;i++){
         //       cout<<b[i]<<" ";
         //   }cout<<endl;
        //    cout<<"f "<<solve(y)<<endl;

        mp[solve(y)]=1;
        return ;
    }
    for(int i=0;i<=5;i++){
        b[x]=i;
        dfs(x+1,y);
    }
}
void solve1(int x){
    int t=log2(x);
    if((1ll<<t)<x) t++;
    for(int i=1;i<=x;i++){
        b[i]=a[i];
    }
    dfs(x+1,(1<<t));
}
void work(){
    for(int i=0;i<4;i++) do_pre[i]=read();
    for(int i=1;i<=n;i++){
        a[i]=(a1[i]^do_pre[i%4]);
        mp[i]=0;
    }

 //   cout<<114<<endl;
    int ans=0,pr=0;
    int t=log2(n);
    if((1<<t)<n) t++;
    for(int i=1;i<=m;i++){
            for(int i=1;i<=(1<<t);i++){
                mp[i]=0;
            }
        solve1(c[i]);
        ans=0;
        for(int i=1;i<=(1<<t);i++){
            if(mp[i]) ans+=i;
        }
     //   cout<<"i "<<i<<" "<<ans<<endl;
        pr^=(i*ans);
    }
    write(pr);puts("");
    return ;
}
void worka(){
    for(int i=0;i<4;i++) do_pre[i]=read();
    for(int i=1;i<=n;i++){
        a[i]=(a1[i]^do_pre[i%4]);
        b[i]=a[i];
        yc[i]=0;
    }
    int tt=log2(n);
    if((1<<tt)<n) tt++;
    for(int i=0;i<=tt;i++){
        yc[(1<<i)]=solve(1<<i);
    //    cout<<(1<<i)<<" "<<yc[(1<<i)]<<endl;
    }
    int pr=0;
    for(int i=1;i<=m;i++){
        pr^=(i*yc[c[i]]);
     //   cout<<i*yc[c[i]]<<endl;
    }
    write(pr);puts("");
}
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a1[i]=read();
    }
    for(int i=1;i<=m;i++){
        c[i]=read();
    }
    int tt=log2(n);
    if((1<<tt)<n) tt++;
    for(int i=1;i<=tt;i++){
        for(int j=0;j<(1<<(tt-i));j++){
            char x;cin>>x;
            d[i][j+1]=x-'0';
        }
    }
    int T=read();
    while(T--){
        if(n<=8) work();
        else worka();
    }
    return 0;
}
