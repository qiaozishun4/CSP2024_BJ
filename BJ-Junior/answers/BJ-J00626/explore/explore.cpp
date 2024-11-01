#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,k,x,y,d,ans,a,b,e[1010][1010];
char c[1010][1010];
string s;
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                c[i][j]='x';
                e[i][j]=0;
            }
        }
        ans=0;
        a=0;
        b=0;
        cin>>n>>m>>k>>x>>y>>d;
        e[x][y]=1;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++){
                c[i][j]=s[j-1];
            }
        }
        for(int i=1;i<=k;i++){
            a=x;
            b=y;
            if(d==0){
                b++;
            }
            else if(d==1){
                a++;
            }
            else if(d==2){
                b--;
            }
            else{
                a--;
            }
            if(1<=a && a<=n && 1<=b && b<=m && c[a][b]=='.'){
                x=a;
                y=b;
                e[x][y]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=e[i][j];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
