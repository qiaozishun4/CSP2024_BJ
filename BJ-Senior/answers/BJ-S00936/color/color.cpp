#include<bits/stdc++.h>
using namespace std;
#define int long long
#define LD long double
#define pii pair<int,int>
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
int read(){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();};while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=1000010,N=15,MAXM=2010,inf=1000000000;
int n,ans,V,a[MAXN],p[MAXN],f[MAXN];
void dfs(int now){
    if(now==n+1){
        int lstb=0,lstr=0,sum=0;
        for(int i=1;i<=n;i++){
            if(p[i])sum+=lstb==a[i]?a[i]:0,lstb=a[i];
            else sum+=lstr==a[i]?a[i]:0,lstr=a[i];
        }
        ans=max(ans,sum);
        return;
    }
    p[now]=0;
    dfs(now+1);
    p[now]=1;
    dfs(now+1);
}
void slv1(){
    dfs(1);
    printf("%lld\n",ans);
}
// struct segtree{
//     int t[MAXN<<2],lz[MAXN<<2];

// }
void slv2(){
    for(int i=0;i<=V;i++)f[i]=-inf;
    f[0]=0;
    int mx=0,sum=0;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            f[a[i]]=max(mx-a[i],f[a[i]]);
            mx=max(mx,f[a[i]]);
            sum+=a[i];
        }
        else{
            int tmp=max(mx+sum,f[a[i]]+a[i]+sum);
            f[a[i-1]]=max(f[a[i-1]],tmp-sum);
            mx=max(mx,f[a[i-1]]);
        }
    }
    printf("%lld\n",mx+sum);
}
void slv(){
    n=read();
    ans=0;   
    for(int i=1;i<=n;i++)a[i]=read(),V=max(V,a[i]);
    if(n<=15)slv1();
    else slv2();
}
signed main(){
    freopen("color.in","r",stdin);freopen("color.out","w",stdout);
    int _=read();while(_--)
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}