#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
bool a[N][N];
bool b[N][N];
int n=0,m=0,k=0,x_0=0,y_0=0,d_0=0;
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=false;
        }
    }
    return ;
}
void go(){
    if(d_0==0 && y_0!=m && !a[x_0][y_0+1])y_0++;
    else if(d_0==1 && x_0!=n && !a[x_0+1][y_0])x_0++;
    else if(d_0==2 && y_0!=1 && !a[x_0][y_0-1])y_0--;
    else if(d_0==3 && x_0!=1 && !a[x_0-1][y_0])x_0--;
    else d_0=(d_0+1)%4;
    b[x_0][y_0]=true;
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x_0,&y_0,&d_0);
        b[x_0][y_0]=true;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<=s.size();j++){
                if(s[j]=='.')a[i][j+1]=0;
                else a[i][j+1]=1;
            }
        }
        while(k--){
            go();
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j])ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
