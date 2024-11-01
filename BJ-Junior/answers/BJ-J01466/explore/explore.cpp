#include<bits/stdc++.h>
using namespace std;
int step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[1010][1010];
struct robot{
    int x;
    int y;
    int facing;
};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        robot T0;
        cin>>T0.x>>T0.y>>T0.facing;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>s[i][j];
        }
        s[T0.x][T0.y]='X';
        while(k--){
            int dx=T0.x+step[T0.facing][0];
            int dy=T0.y+step[T0.facing][1];
            if(dx>0&&dx<=n&&dy>0&&dy<=m&&s[dx][dy]!='x'){
                T0.x=dx;
                T0.y=dy;
                if(s[dx][dy]=='.') ans++;
                s[dx][dy]='X';
            }else{
                T0.facing+=1;
                T0.facing%=4;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
