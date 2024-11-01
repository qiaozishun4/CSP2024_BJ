#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int t,n,a[N];
int c[110][110],f[110][110];
int j;
void init(){
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        init();
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                j=i+l-1;
                if(l==2){
                    if(a[i]==a[j]) c[i][j]=a[i];
                }
                else{
                    for(int k=i;k<j;k++){
                        c[i][j]=max(c[i][j],c[i][k]+c[k+1][j]);
                    }
                    if(a[i]==a[j]) c[i][j]=max(c[i][j],c[i+1][j-1]+a[i]);
                }
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                j=i+l-1;
                if(l==2){
                    f[i][j]=c[i][j];
                    continue;
                }
                for(int k=i;k<j;k++){
                    f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
                }
                if(a[i]==a[j]) f[i][j]=max(f[i][j],c[i+1][j-1]+a[i]);
            }
        }
        printf("%lld\n",f[1][n]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}