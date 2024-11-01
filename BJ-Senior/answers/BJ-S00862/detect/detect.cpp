#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10,M = 2e3+10;
#define double long double
int T,n,m,l,v,p[N],dp[M][M];
struct Q{
    double d;
    double v;
    double a;
}c[N];
struct G{
    double l;
    double r;
}f[N];
void subtask1(){
    int cnt=0;
    bool flag2=true;
    for(int i=1;i<=n;i++){
        bool flag=false;
        if(c[i].a<0) flag2=false;
        double x;
        for(int j=1;j<=m;j++){
            if(p[j]<c[i].d) continue;
            if(c[i].v<v&&c[i].a<0) continue;
            if(c[i].a>0){
                double tmp=(v-c[i].v)/c[i].a;
                double z=c[i].v*tmp+c[i].a*tmp*tmp/2;
                if(z<(p[j]-c[i].d)){
                    x=z+(double)c[i].d;
                    int tmp2=tmp;
                    int A=c[i].a;
                    if(tmp2*A==(v-c[i].v)&&((A%2==0)||(tmp2%2==0))){
                        x++;
                    }
                    flag=true;
                }
            }
            else if(c[i].a==0){
                if(c[i].v>v){
                    flag=true;
                    x=(double)l;
                }
            }
            else if(c[i].a<0){
                double tmp=(v-c[i].v)/c[i].a;
                double z=c[i].v*tmp+c[i].a*tmp*tmp/2;
                int tmp2=tmp;
                int A=c[i].a;
                if(z>(p[j]-c[i].d)){
                    flag=true;
                    x=z+(double)c[i].d;
                    if(tmp2*A==(v-c[i].v)&&((A%2==0)||(tmp2%2==0))){
                        x--;
                    }
                }
            }
        }
        if(flag){
            cnt++;
            if(c[i].a<0){
                f[cnt].l=c[i].d;
                f[cnt].r=x;
            }
            if(c[i].a==0){
                f[cnt].l=c[i].d;
                f[cnt].r=x;
            }
            if(c[i].a>0){
                f[cnt].l=x;
                f[cnt].r=(double)l;
            }
        }
    }
    cout<<cnt<<" ";
    if(flag2){
        if(cnt==0) cout<<m<<endl; 
        else cout<<m-1<<endl;
    }
    else{
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=m;j++){
                if(f[i].l<=p[j]){
                    f[i].l=j;
                    break;
                }
            }
            for(int j=m;j>=1;j--){
                if(f[i].r>=p[j]){
                    f[i].r=j;
                    break;
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=0;k<=i;k++){
                    int tot=0;
                    for(int q=1;q<=cnt;q++){
                        if(f[q].l>k&&f[q].r>=i&&f[q].l<=i){
                            tot++;
                        }
                    }
                    dp[i][j]=max(dp[k][j-1]+tot,dp[i][j]);
                }
            }
        }
        int ans=m;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                if(dp[i][j]==cnt){
                    ans=min(ans,j);
                }
            }
        }
        cout<<m-ans<<endl;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        if(n<=3000&&m<=3000){
            subtask1();
        }
    }
    return 0;
}