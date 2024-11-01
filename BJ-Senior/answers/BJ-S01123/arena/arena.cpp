#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define int long long
int t,n,m,a[maxn],c[maxn],k,x[7],win[20][maxn],lg[maxn];
bool d[20][maxn];
int read(void){
    int x=0,op=1;
    char ch=getchar();
    if(ch=='-'){
        op=-1;
    }
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-'){
            op=-1;
        }
    }
    while(ch>='0'&&ch<='9'){
        x*=10;
        x+=ch-'0';
        ch=getchar();
    }
    return x*op;
}
signed main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    n=read();
    for(int i=2;i<=n;i++){
        lg[i]=lg[i/2]+1;
    }
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=m;i++){
        c[i]=read();
    }
    while((1<<k)<n){
        k++;
    }
    for(int i=1;i<=k;i++){
        string s;
        cin>>s;
        for(int j=1;j<=s.size();j++){
            d[i][j]=s[j-1]-'0';
        }
    }
    k=0;
    while((1<<(k+1))<=n){
        k++;
    }
    t=read();
    while(t--){
        x[0]=read();
        x[1]=read();
        x[2]=read();
        x[3]=read();
        for(int i=1;i<=n;i++){
            a[i]^=x[i&3];
        }
        for(int j=1;j<=(1<<(k-1));j++){
            if(d[1][j]&&a[j<<1]<1||!d[1][j]&&a[(j<<1)-1]>0){
                win[1][j]=(j<<1)-1;
            }
            else{
                win[1][j]=j<<1;
            }
        }
        for(int i=2;i<=k;i++){
            for(int j=1;j<=(1<<(k-i));j++){
                if(d[i][j]&&a[win[i-1][j<<1]]<i||!d[i][j]&&a[win[i-1][(j<<1)-1]]>=i){
                    win[i][j]=win[i-1][(j<<1)-1];
                }
                else{
                    win[i][j]=win[i-1][j<<1];
                }

            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(c[i]==1){
                ans^=i;
            }
            else{
                ans^=i*win[lg[c[i]]][1];
            }
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++){
            a[i]^=x[i&3];
        }
    }
    return 0;
}
