#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, cnt;
char a[1010][1010];
bool b[1010][1010];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>t;
    while(t--){
        cnt = 0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>a[i][j];
                b[i][j] = false;
            }
        }
        for(int i = 1; i <= k + 1; i++){
            if(!b[x][y]) cnt++;
            b[x][y] = true;
            //cout<<"("<<x<<", "<<y<<", "<<d<<")"<<endl;
            int nx, ny;
            if(d == 0) nx = x, ny = y + 1;
            else if(d == 1) nx = x + 1, ny = y;
            else if(d == 2) nx = x, ny = y - 1;
            else if(d == 3) nx = x - 1, ny = y;
            //cout<<"("<<nx<<", "<<ny<<")"<<endl;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.'){
                x = nx, y = ny;
            }
            else{
                d = (d + 1) % 4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
