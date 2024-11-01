//17:55 third E:50 rp++
#include<bits/stdc++.h>
using namespace std;
const int N=2003;
inline int read(){
    int x=0,w=1;
    char ch=getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-')w=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())x=10*x+ch-'0';
    return x*w;
}
int n,a[N];
long long ans,f[N][N][2][2];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T=read();
    while(T--){
        ans=0,n=read(),memset(f,0,sizeof f);
        for(int i=1;i<=n;++i)a[i]=read();
        for(int i=1;i<=n;++i){
            for(int j=0;j<i-1;++j){
                f[i][j][0][0]=f[i-1][j][1][0]+(a[i]==a[j]?a[i]:0);
                f[i][i-1][0][1]=max(f[i][i-1][0][1],f[i][j][0][0]);
                f[i][j][1][1]=f[i-1][j][0][1]+(a[i]==a[j]?a[i]:0);
                f[i][i-1][1][0]=max(f[i][i-1][1][0],f[i][j][1][1]);
                f[i][j][0][1]=f[i-1][j][0][1]+(a[i]==a[i-1]?a[i]:0);
                f[i][i-1][0][0]=max(f[i][i-1][0][0],f[i][j][0][1]);
                f[i][j][1][0]=f[i-1][j][1][0]+(a[i]==a[i-1]?a[i]:0);
                f[i][i-1][1][1]=max(f[i][i-1][1][1],f[i][j][1][0]);
            }
        }
        ans=max(f[n][n-1][0][0],f[n][n-1][0][1]);
        printf("%lld\n",ans);
    }
    return 0;
}