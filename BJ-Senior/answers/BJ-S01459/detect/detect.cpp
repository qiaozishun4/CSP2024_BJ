#include<iostream>
#include<cmath>
using namespace std;
const int Maxn=3005;
int T,n,m,L,V,a[Maxn],v[Maxn],d[Maxn],p[Maxn],z[Maxn][Maxn],k[Maxn];
int f(int d,int v,int a,int p){
    return sqrt(v*v+2*a*(p-d));
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                z[i][j]=f(d[i],v[i],a[i],p[i]);
                if(z[i][j]>=V)z[i][j]=1;
                else if(z[i-1][j]==1){
                    z[i][j]=2;
                    k[i-1]++;
                }else if(z[i-1][j]==2)z[i][j]==3;
            }
        }
        for(int i=1;i<=m;i++){
            if(z[m][i])ans++;
        }
        cout<<ans<<" "<<ans-1;
    }
    return 0;
}
