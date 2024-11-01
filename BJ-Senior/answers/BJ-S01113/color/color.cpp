#include <bits/stdc++.h>
using namespace std;
long long N = 1e16, M = 1e16;
int g[N][M];
int XX = {1, -1, 0, 1};
int yy = (-1, 1, 1, 0);
bool k = {0};
int n, m, l;
int s = 0;
void k(int n; int m){
    if(n == m){
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
        }{
            if(g[i][j] == 1){
                i = i + 1;
                j = j - 1;
            } else if(g[i + 1][j - 1]){
                j = j + 1;
                while(p){
                    p = 4;
                    bool a[4];
                    if(g[i][j + 1] == 1){
                        p--;
                        a[p] = 1;
                    } else {
                        continue;
                    }
                }
                s++;
            }
        }
    }
    k(n, -1);
    k(m, 1);
    k(n, 1);
    k(m, -1)
}
int main(){
    cin >> n >> m;
    cin >> l;
    int d[2005];
    for(int i = 1; i <= l; i++){
        cin >> d[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == d[i] && j == d[i]){
                g[i][j] == 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[i][j] == g[j][i]){
                if(g[i][j]){
                    g[i][j] = 2;
                } else {
                    continue;
                }
            } else {
                g[i][j] = 1;
                g[j][i] = 2;
            }
        }
    }
    k(n, m);
    cout << s;
    return 0;
}