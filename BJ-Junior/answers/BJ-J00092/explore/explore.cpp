#include <bits/stdc++.h>
using namespace std;
int t;
long long cnt = 1;
char a[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int o = 0; o < t; o++){
        int n,m,step,x,y,d;
        cin>>n>>m>>step>>x>>y>>d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>a[i][j];
            }
        }
        for(int i = 0; i < step; i++){
            if(d == 0){
                if(a[x][y+1] != 0 && a[x][y+1] != 'x'){
                    cnt++;
                    y++;
                }else
                    d++;
                    continue;
            }if(d == 1){
                if(a[x+1][y] != 0 && a[x+1][y] != 'x'){
                    cnt++;
                    x++;
                }else
                    d++;
                    continue;
            }if(d == 2){
                if(a[x][y-1] != 0 && a[x][y-1] != 'x'){
                    cnt++;
                    y--;
                }else
                    d++;
                    continue;
            }if(d == 3){
                if(a[x-1][y] != 0 && a[x-1][y] != 'x'){
                    cnt++;
                    x--;
                }else
                    d = 0;
                    continue;
            }
            cout<<x<<' '<<y<<' '<<d<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
