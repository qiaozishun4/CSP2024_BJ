#include<iostream>
using namespace std;

int a[1005][1005],dy[4] = {1,0,-1,0},dx[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n,m,k,x,y,d;
        cin >> n >> m >> k >> x >> y >> d;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char c;
                cin >> c;
                a[i][j] = (c=='.' ? 0 : -1);
            }
        }

        for(int i = 0; i <= n+1; i++){
            a[i][0] = a[i][m+1] = -1;
        }
        for(int j = 0; j <= m+1; j++){
            a[0][j] = a[n+1][j] = -1;
        }

        a[x][y] = 1;
        while(k--){
            //cout << x <<y << d << " " << a[x+dx[d]][y+dx[d]] << endl;
            if(a[x+dx[d]][y+dy[d]] == -1){
                d++;
                d %= 4;
            }
            else{
                x += dx[d];
                y += dy[d];
            }
            a[x][y] = 1;
        }
        /*
        for(int i = 0; i <= n+1; i++){
            for(int j = 0; j <= m+1; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        */
        int s = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == 1){
                    s++;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
