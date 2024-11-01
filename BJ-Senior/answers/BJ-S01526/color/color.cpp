#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N=2e5+10,M=2010;

int n,a[N];
LL f[M][M][2];
struct Node{
    int i,j,k;
}d[M][M][2];
int st[M];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        for(int i=0;i<=n+10;++i)
            for(int j=0;j<=n+10;++j)
                for(int k=0;k<=1;++k){
                    f[i][j][k]=0;
                    d[i][j][k]={0,0,0};
                }
        for(int i=1;i<=n;++i) st[i]=0;
        for(int i=1;i<=n;++i){
            for(int j=2;j<=i;++j){
                for(int l=i-1;l>=1 && l>=j-1;--l){
                    if(a[i]==a[l]){
                        if(f[i][j][1]<f[l][j-1][1]+a[i]){
                            f[i][j][1]=f[l][j-1][1]+a[i];
                            d[i][j][1]={l,j-1,1};
                        }
                    }
                    else{
                        if(f[i][j][1]<f[l][j-1][1]){
                            f[i][j][1]=f[l][j-1][1];
                            d[i][j][1]={l,j-1,1};
                        }
                    }
                }
            }
            /*for(int j=0;j<i;++j){
                for(int l=i-1;l>=1 && l-1>=j;--l){

                }
            }*/
        }
        Node r={1,1,1};
        for(int i=2;i<=n;++i)
            for(int j=1;j<=i;++j)
                if(f[r.i][r.j][r.k]<f[i][j][1])
                    r={i,j,1};
        LL ans=f[r.i][r.j][r.k];
        while(r.k==1){
            st[r.i]=1;
            r=d[r.i][r.j][r.k];
        }
        int j=0;
        for(int i=1;i<=n;++i){
            if(st[i]) continue;
            if(j && a[j]==a[i]) ans+=a[i];
            j=i;
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}