#include <cstdio>
#include <bitset>
#define MAXN 1010
using namespace std;
int t,n,m,k,asw;
int rx,ry,d;
bitset<MAXN> G[MAXN],vis[MAXN];
char buff[MAXN];
char fx[4]{'E','S','W','N'};
void mover() {
    int tx=rx,ty=ry;
    switch (d) {
    case 0:
        ty++;
        break;
    case 1:
        tx++;
        break;
    case 2:
        ty--;
        break;
    case 3:
        tx--;
        break;
    }
    if (tx>=1&&tx<=n&&ty>=1&&ty<=m&&G[tx][ty]==0) {
        rx=tx,ry=ty;
    } else {
        d=(d+1)%4;
    }
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&rx,&ry,&d);
        for (int i=0;i<MAXN;i++) {
            G[i].reset();
            vis[i].reset();
        }
        for (int i=1;i<=n;i++) {
            scanf("%s",buff+1);
            for (int j=1;j<=m;j++) {
                if (buff[j]=='x') {
                    G[i][j]=1;
                }
            }
        }
        asw=0;
        k++;
        while (k--) {
			if (!vis[rx][ry]) {
				asw++;
			}
            //printf("move to point (%d,%d), d=%d:%c\n",rx,ry,d,fx[d]);
            vis[rx][ry]=1;
            mover();
        }
        printf("%d\n",asw);
    }
    return 0;
}
