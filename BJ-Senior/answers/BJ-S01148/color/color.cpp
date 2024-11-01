#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e3+5;
int n,ans,maxn=0;
int a[N];
int p[N];
int now[N];
int s[N];
int f[N][N];
void dfs(int x){
    if(x==n+1){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(now[i]==now[j]){
                    if(a[i]==a[j]){
                        sum+=a[j];
                    }
                    break;
                }
            }
        }
        // for(int i=1;i<=maxn;i++)cout<<now[i]<<" ";
        // for(int i=1;i<=n;i++)cout<<noww[i]<<" ";
        // cout<<sum<<endl;
        ans=max(ans,sum);
        return;
    }
    now[x]=1;
    dfs(x+1);
    now[x]=0;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        maxn = 0;
        for(int i=0;i<=2;i++)p[i]=1000000;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn=max(maxn,a[i]);
        }
        // cout << maxn << endl;
        if(n<=15){
            ans=0;
            dfs(1);
            cout<<ans<<endl;
            continue;
        }
        for(int len=1;len<=n;len++){
            for(int L=1;L+len-1<=n;L++){
                int R=L+len-1;
                for(int i=L;i<=R;i++){
                    for(int j=i+1;j<=R;j++){
                        int cur=f[L][i]+f[i+1][j-1]+f[j][R];
                        if(a[i]==a[j])cur+=a[j];
                        f[L][R]=max(f[L][R],cur);
                    }
                }
                // cout << L << " " << R << " " << f[L][R] << endl;
            }
        }
        cout<<f[1][n]<<endl;
    }
    return 0;
}
// 565203
// 440224
