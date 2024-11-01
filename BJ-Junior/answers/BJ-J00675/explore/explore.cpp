#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+9;
int to[4][2] = {0,1,1,0,0,-1,-1,0};
char a[maxn][maxn];
bool vis[maxn][maxn];
struct node{
    int x,y,d;
};
queue<node>q;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n,m,k,x1,y1,d0;
        cin>>n>>m>>k>>x1>>y1>>d0;
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
                cin>>a[i][j];
        int ans = 1;
        q.push({x1,y1,d0});
        vis[x1][y1] = 1;
        while(k--){
            node h = q.front();
            q.pop();
            int tx = h.x+to[h.d][0];
            int ty = h.y+to[h.d][1];
            if(tx>=1 &&tx<=n && ty>=1 && ty<=m && a[tx][ty] != 'x'){
                q.push({tx,ty,h.d});
                if(!vis[tx][ty]){
                    ans++;
                    vis[tx][ty] = 1;
                }
            }else{
                q.push({h.x,h.y,(h.d+1)%4});
            }
            //cout<<h.x<<" "<<h.y<<" "<<endl;
        }
        cout<<ans<<endl;
        q.pop();
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
                vis[i][j] = 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

