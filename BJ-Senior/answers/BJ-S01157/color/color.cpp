#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long f[2][2005][2005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,maxs=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxs=max(maxs,a[i]);
        }
        memset(f,-1,sizeof(f));
        f[0][a[1]][a[2]]=0;
        f[0][a[2]][a[1]]=0;
        f[0][a[2]][0]=0;
        if(a[1]==a[2]){
            f[0][a[2]][0]=a[1];
        }
        f[0][0][a[2]]=0;
        if(a[1]==a[2]){
            f[0][0][a[2]]=a[1];
        }
        for(int i=3;i<=n;i++){
            for(int j=0;j<=min(2000,maxs);j++){
                for(int k=0;k<=min(2000,maxs);k++){
                    f[i%2][j][k]=-1;
                }
            }
            for(int j=0;j<=min(2000,maxs);j++){
                for(int k=0;k<=min(2000,maxs);k++){
                    if(f[(i-1)%2][j][k]!=-1){
                        if(a[i]==j){
                            f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k]+a[i]);
                        }
                        else{
                            f[i%2][a[i]][k]=max(f[i%2][a[i]][k],f[(i-1)%2][j][k]);
                        }
                        if(a[i]==k){
                            f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k]+a[i]);
                        }
                        else{
                            f[i%2][j][a[i]]=max(f[i%2][j][a[i]],f[(i-1)%2][j][k]);
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=min(2000,maxs);i++){
            for(int j=1;j<=min(2000,maxs);j++){
                ans=max(ans,f[n%2][i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


