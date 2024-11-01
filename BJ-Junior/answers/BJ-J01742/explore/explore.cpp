#include<bits/stdc++.h>
using namespace std;
string a[1111];
bool b[1111][1111];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i = 1;i <= n;i += 1){
            for(int j = 1;j <= m;j += 1){
                cin>>a[i][j];
            }
        }
        for(int i = 0;i < k;i += 1){
            int tx = x,ty = y;
            b[x][y] = 1;
            if(d == 0){
                ty += 1;
            }
            if(d == 1){
                tx += 1;
            }
            if(d == 2){
                ty -= 1;
            }
            if(d == 3){
                tx -= 1;
            }
            if(tx <= n && ty <= m && tx > 0 && ty > 0 && a[tx][ty] == '.'){
                x = tx;
                y = ty;
            }
            else{
                d = (d + 1) % 4;
            }
        }
        b[x][y] == 1;
        int ccc = 0;
        for(int i = 1;i <= n;i += 1){
            for(int j = 1;j <= m;j += 1){
                if(b[i][j] == 1){
                    ccc += 1;
                }
            }
        }
        cout<<ccc;
    }
    return 0;
}
