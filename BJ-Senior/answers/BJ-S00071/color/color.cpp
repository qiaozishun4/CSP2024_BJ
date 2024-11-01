#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int n=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) n=n*10+c-'0';
    return n*f;
}
void read(int &n){
    n=0;
    int f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) n=n*10+c-'0';
    n*=f;
}
void write(int x){
    if(x<0){
        putchar('-');
        write(-x);
        return ;
    }
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
const int N=2e3+5;
ll dp[N][N],ans;
int T,n,a[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(dp,0,sizeof(dp));
        ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i+1][j]=max(dp[i][j]+a[i+1]*(a[i]==a[i+1]),dp[i+1][j]);
                dp[i+1][i]=max(dp[i][j]+a[i+1]*(a[j]==a[i+1]),dp[i+1][i]);
                if(i==n) ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

