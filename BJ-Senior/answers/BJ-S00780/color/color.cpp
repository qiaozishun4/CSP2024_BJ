#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2010;
const int A = 2010;
const int INF = 0x3f3f3f3f;


int f[N][A], g[2000010][15];
int T, n, a[2000010];

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        if(n <= 2000){
            int m = 0;
            for(int i = 0; i < n; i++){
                scanf("%d", &a[i]);
                if(a[i] > m)
                    m = a[i];
            }
            memset(f, 0xff, sizeof(f));
            f[0][0] = 0;
            for(int i = 0; i < n-1; i++)
                for(int j = 0; j <= m; j++){
                    if(f[i][j] == -1) continue;
                    // printf("f[%d][%d]=%d\n", i, j, f[i][j]);
                    f[i + 1][j] = max(f[i + 1][j], f[i][j] + (a[i]==a[i+1])*a[i]);
                    f[i + 1][a[i]] = max(f[i + 1][a[i]], f[i][j] + (a[i+1]==j)*j);
                    // if(i==1 && j==1){
                    //     printf("f[1][1] + (%d(a[%d])==%d)*%d=%d, f[%d][%d] = %d, m = %d\n", a[i+1], i+1, j, j, f[i][j] + (a[i+1]==j)*j, i+1, a[i], f[i+1][a[i]], m);
                    // }
                }
            int ans = 0;
            for(int j = 0; j <= m; j++)
                if(f[n-1][j] > ans)
                    ans = f[n-1][j];
            printf("%d\n", ans);
        }
        else{
            int m = 0;
            for(int i = 0; i < n; i++){
                scanf("%d", &a[i]);
                if(a[i] > m)
                    m = a[i];
            }
            // printf("m=%d\n", m);
            // if(m > 10) {printf("ERROR!\n"); break;}
            memset(g, 0xff, sizeof(g));
            g[0][0] = 0;
            for(int i = 0; i < n-1; i++)
                for(int j = 0; j <= m; j++){
                    if(g[i][j] == -1) continue;
                    g[i + 1][j] = max(g[i + 1][j], g[i][j] + (a[i]==a[i+1])*a[i]);
                    g[i + 1][a[i]] = max(g[i + 1][a[i]], g[i][j] + (a[i+1]==j)*j);
                }
            int ans = 0;
            for(int j = 0; j <= m; j++)
                if(g[n-1][j] > ans)
                    ans = g[n-1][j];
            printf("%d\n", ans);
        }
    }
}