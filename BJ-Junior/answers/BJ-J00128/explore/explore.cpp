#include <iostream>
#include <cstring>
using namespace std;
int T,n,m,k,sx,sy,sd,f[5][5]={{0,1},{1,0},{0,-1},{-1,0}},ans,sign[1005][1005];
char mp[1005][1005];
bool check(int x,int y){
    if(x<=0||y<=0||x>n||y>m||mp[x][y]=='x')return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(sign,0,sizeof(sign));
        cin >> n >> m >> k>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> mp[i][j];
            }
        }
        ans=0;
        int x=sx,y=sy,d=sd,step=0;
        while(step<=k){
            sign[x][y]++;
            for(int i=d;i<4;i=(i+1)%4){
                int xx=x+f[i][0],yy=y+f[i][1];
                step++;
                if(step>k){
                    break;
                }
                if(check(xx,yy)){
                    x=xx,y=yy,d=i;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(sign[i][j])ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
