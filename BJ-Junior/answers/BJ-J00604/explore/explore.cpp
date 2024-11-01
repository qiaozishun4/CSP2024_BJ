#include <iostream>
#include <cstring>
using namespace std;
int T;
int n,m,k,x,y,d;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int mp[1010][1010];
string str;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        memset(mp,0,sizeof(mp));
        for(int i = 1; i <= n; i++){
            cin>>str;
            for(int j = 1; j <= m; j++){
                if(str[j-1] == '.'){
                    mp[i][j] = 0;
                }else if(str[j-1] == 'x'){
                    mp[i][j] = 1;
                }
            }
        }
        mp[x][y] = 2;
        while(k--){
            if(mp[x+dx[d]][y+dy[d]] != 1 && x+dx[d] <= n && x+dx[d] >= 1 && y+dy[d] <= m && y+dy[d] >= 1){
                x = x+dx[d];
                y = y+dy[d];
                mp[x][y] = 2;
            }else{
                d = (d+1)%4;
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                    //printf("%d ",mp[i][j]);
                if(mp[i][j] == 2){
                    ans++;
                }
            }
            //printf("\n");
        }
        printf("%d\n",ans);
    }
    return 0;
}
