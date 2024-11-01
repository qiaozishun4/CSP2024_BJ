#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=1010;
int n,m,k,ans,a[MAXN][MAXN],mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
char c[MAXN][MAXN];
void move(int &x,int &y,int &d){
    int nx=x+mx[d],ny=y+my[d];
    if(!nx||!ny||nx>n||ny>m||c[nx][ny]=='x')d++,d%=4;
    else x=nx,y=ny;
}
void slv(){
    ans=0;
    n=read(),m=read(),k=read();
    int x=read(),y=read(),d=read();
    for(int i=1;i<=n;i++){
        scanf("%s",c[i]+1);
    }
    a[x][y]=1;
    while(k--)move(x,y,d),a[x][y]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=a[i][j];
            a[i][j]=0;
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("explore.in","r",stdin);freopen("explore.out","w",stdout);
    int _=read();while(_--)
    slv();
    fclose(stdin);fclose(stdout);
    return 0;
}