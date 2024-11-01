#include <bits/stdc++.h>
using namespace std;
int T,n;
typedef long long ll;
const int N=2e5+5;
ll f[2005][2005],a[N];
ll t[N];

int calc(int l,int r){
    if(l<1) return 0;
    if(a[l]==a[r]) return a[l];
    else return 0;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]) t[i]=a[i];
            t[i]=t[i-1]+t[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=-1e16;
            }
        }
        f[1][1]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i-1;j++){
                f[i][j+1]=max(f[i][j+1],f[i-1][j]+calc(i-1,i));
                //cout<<i<<' '<<j+1<<' '<<f[i][j+1]<<endl;
            }
            for(int j=1;j<i;j++){
                f[i][1]=max(f[i][1],f[i-1][j]+calc(i-j-1,i));
                //cout<<i<<' '<<f[i][1]<<endl;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,f[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}