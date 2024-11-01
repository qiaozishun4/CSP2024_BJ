#include <bits/stdc++.h>
using namespace std;

const int N=2005;

int T,n,a[N],f[N][N];

int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>T;
    while(T--) {
        memset(f,0,sizeof(f));
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        f[1][0]=f[0][1]=0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=n;j++) {
                for(int k=0;k<=n;k++) {
                    if(i<j || i<k || j==k) continue;
                    if(i!=j && i!=k) continue;
                    if(i==j) {
                        if(k!=i-1) {
                            if(a[i]==a[i-1]) f[j][k]=f[i-1][k]+a[i];
                            else f[j][k]=f[i-1][k];
                        } else {
                            for(int l=0;l<i;l++) {
                                if(a[i]==a[l]) f[j][k]=max(f[j][k],f[l][i-1]+a[i]);
                                else f[j][k]=max(f[j][k],f[l][i-1]);
                            }
                        }
                    } else {
                        if(j!=i-1) {
                            if(a[i]==a[i-1]) f[j][k]=f[j][i-1]+a[i]; 
                            else f[j][k]=f[j][i-1];
                        } else {
                            for(int l=0;l<i;l++) {
                                if(a[i]==a[l]) f[j][k]=max(f[j][k],f[i-1][l]+a[i]);
                                else f[j][k]=max(f[j][k],f[i-1][l]);
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) ans=max(f[n][i],max(ans,f[i][n]));
        cout<<ans<<"\n";
    }
    return 0;
}//pls