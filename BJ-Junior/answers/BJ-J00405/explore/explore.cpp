#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
bool maze[1005][1005];

int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t --) {
        memset(maze,0,sizeof(maze));
        set<pair<int,int> > s;
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int x,y,d;
        scanf("%d %d %d",&x,&y,&d);
        s.insert({x,y});
        //printf("%d %d %d\n",x,y,k);
        for(int i = 1;i<=n;i++) {
            getchar();
            for(int j = 1;j<=m;j++) {
                char op;
                scanf("%c",&op);
                if(op == 'x') {
                    maze[i][j] = 1;
                }
                else {
                    maze[i][j] = 0;
                }
            }
        }
        for(int i = 1;i<=k;i++) {
            int nx,ny;
            if(d == 0) {
                nx = x;
                ny = y + 1;
            }
            else if(d == 1) {
                nx = x + 1;
                ny = y;
            }
            else if(d == 2) {
                nx = x;
                ny = y - 1;
            }
            else if(d == 3) {
                nx = x - 1;
                ny = y;
            }
            //printf("%d %d %d %d\n",nx,ny,d,maze[nx][ny]);
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !maze[nx][ny]) {
                x = nx;
                y = ny;
            }
            else {
                d = (d + 1) % 4;
            }
            s.insert({x,y});
        }
        printf("%d\n",s.size());
    }
    return 0;
}
