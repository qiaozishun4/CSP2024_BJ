#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n,m,k,sum=1;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        char a[n+5][m+5][2]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j][0];
            }
        }
        a[x][y][1]=1;
        while(k--){
            if(d==0){
                if(y+1<=m&&a[x][y+1][0]=='.'){
                    y++;
                    if(!a[x][y][1])
                    sum++;
                    a[x][y][1]=1;
                }else{
                    d=1;
                }
            }else if(d==1){
                if(x+1<=n&&a[x+1][y][0]=='.'){
                   x++;
                   if(!a[x][y][1])
                   sum++;
                   a[x][y][1]=1;
                }else
                    d=2;
            }else if(d==2){
                if(y-1>=1&&a[x][y-1][0]=='.'){
                    y--;
                    if(!a[x][y][1])
                    sum++;
                    a[x][y][1]=1;
                }else
                    d=3;
            }else{
                if(x-1>=1&&a[x-1][y][0]=='.'){
                    x--;
                    if(!a[x][y][1])
                    sum++;
                    a[x][y][1]=1;
                }else
                   d=0;
            }
        }
        cout <<sum << '\n';
    }
    return 0;
}
