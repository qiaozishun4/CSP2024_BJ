#include<iostream>
#define int long long
using namespace std;
const int N=2e3+100;
int a[N],f[N][N],ans;
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    int n;
    cin>>T;
//    T=5;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                f[i][j]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
//                cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
                f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1]*(a[i+1]==a[i]));
                f[i+1][i]=max(f[i+1][i],f[i][j]+a[i+1]*(a[i+1]==a[j]));
            }
        }
        for(int i=1;i<n;i++)
            ans=max(ans,f[n][i]);
        cout<<ans<<endl;
    }
}
