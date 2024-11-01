#include<bits/stdc++.h>
using namespace std;
const int maxn = 10e3+1;
long long t2,t[maxn][maxn];
char c[maxn][maxn];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t2;
    while(t2--){
        long long n,m,k,x,y,d,ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>c[i][j];
                t[i][j]=0;
            }
        }
        t[x][y]=1;
        while(k--){
            long long fx = x,fy = y;
            if(d==0){
                y+=1;
            }
            else if(d==1){
                x+=1;
            }
            else if(d==2){
                y-=1;
            }
            else if(d==3){
                x-=1;
            }
            if((1<=x&&x<=n)&&(1<=y&&y<=m)&&c[x][y]=='.'){
                t[x][y]=1;
            }else{
                x = fx,y = fy;
                d = (d+1)%4;
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(t[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}