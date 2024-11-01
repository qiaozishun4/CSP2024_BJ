#include <bits/stdc++.h>

using namespace std;

const int N=2e3+10,M=2e5+10;
long long f[N][N][2][2],g[N][2][2];
int a[M];
int n,T;

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n>2000) {printf("%d\n",a[1]);continue;}
        long long ans=0;
        for(int i=2;i<=n;i++){
            g[i][0][1]=g[i][1][0]=g[i][1][1]=g[i][0][0]=0;
            for(int j=1;j<i;j++)
                for(int x1=0;x1<=1;x1++)
                    for(int x2=0;x2<=1;x2++){
                        if(x1==x2){
                            if(j==1){
                                //cout<<g[4][1][0]<<" "<<g[4][0][1]<<endl;
                                f[i][j][x1][x2]=g[i-1][x1][!x1]+(a[i]==a[i-1])*a[i];
                                //if(i==5) cout<<f[i][j][x1][x2]<<endl;
                            }
                            else f[i][j][x1][x2]=f[i-1][j-1][x1][x2]+(a[i]==a[i-1])*a[i];
                        }
                        else{
                            if(j==1) f[i][j][x1][x2]=g[i-1][x2][x1]+(a[i]==a[i-j-1])*a[i];
                            else{
                                //if(i==6 && j==2) cout<<f[i-1][j-1][x2][x2]<<endl;
                                f[i][j][x1][x2]=f[i-1][j-1][x2][x2]+(a[i]==a[i-j-1])*a[i];
                            }
                        }
                        ans=max(ans,f[i][j][x1][x2]);
                        g[i][x1][x2]=max(g[i][x1][x2],f[i][j][x1][x2]);
                    }
            //cout<<g[i][0][0]<<" "<<g[i][0][1]<<" "<<g[i][1][0]<<" "<<g[i][1][1]<<endl;
        }
        //cout<<f[5][1][1][1]<<" "<<f[5][1][0][0]<<" "<<f[6][2][0][1]<<" "<<f[6][2][1][0]<<endl;
        printf("%lld\n",ans);
    }
    return 0;
}
