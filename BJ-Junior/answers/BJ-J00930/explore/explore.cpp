#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int T,n,m,k,x,y,d;char di[maxn][maxn];int ans = 1;
bool vis[maxn][maxn];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        ans = 1;
        cin>>n>>m>>k;
        //cout<<n<<" "<<m<<endl;
        cin>>x>>y>>d;
        x--,y--;
        vis[x][y] = 1;
        for(int i = 0 ; i < n ; i++)cin>>di[i];
        //for(int i = 0 ; i <= n ; i++){
           // for(int j = 0 ; j <= m ; j++)cout<<di[i][j];
            //cout<<endl;
        //}
        //cout<<114514<<endl;
        while(k--){
            if(d == 0){
                if(y+1 < m && di[x][y+1] != 'x'){
                    y++;
                    if(!vis[x][y]){
                        vis[x][y] = 1;
                        //cout<<x<<" "<<y<<" "<<k<<" "<<d<<endl;
                        ans++;
                    }
                }
                else{
                    d++;
                    d %= 4;
                }
            }
            else if(d == 1){
                if(x+1 < n && di[x+1][y] != 'x'){
                    x++;
                    if(!vis[x][y]){
                        vis[x][y] = 1;
                        //cout<<x<<" "<<y<<" "<<k<<" "<<d<<endl;
                        ans++;
                    }
                }
                else{
                    d++;
                    d %= 4;
                }
            }
            else if(d == 2){
                if(y-1 >= 0 && di[x][y-1] != 'x'){
                    y--;
                    if(!vis[x][y]){
                        vis[x][y] = 1;
                        //cout<<x<<" "<<y<<" "<<k<<" "<<d<<endl;
                        ans++;
                    }
                }
                else{
                    d++;
                    d %= 4;
                }
            }
            else if(d == 3){
                if(x-1 > 0 && di[x-1][y] != 'x'){
                    x--;
                    if(!vis[x][y]){
                        vis[x][y] = 1;
                        //cout<<x<<" "<<y<<" "<<k<<" "<<d<<endl;
                        ans++;
                    }
                }
                else{
                    d++;
                    d %= 4;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
