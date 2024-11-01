#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin>>T;
    for(int ttt = 1;ttt<=T;ttt++){
        int n,m,k,x,y,d,x1,y1;
        cin>>n>>m>>k;
        char map1[n+5][m+5];
        cin>>x>>y>>d;

        char type;
        for(int i = 1 ;i<=n;i++){
            for(int j = 1 ; j<=m ; j++){
                cin>>type;
                map1[i][j] = type;
            }
        }

        int sum = 1;
        map1[x][y] = '0';
        for(int i=1;i<=k;i++){
            if(d == 0){
                x1 = x;
                y1 = y+1;
            }
            else if(d == 1){
                x1 = x+1;
                y1 = y;
            }
            else if(d == 2){
                x1 = x;
                y1 = y-1;
            }
            else if(d == 3){
                x1 = x-1;
                y1 = y;
            }

            if(x1>=1 && x1<=n && y1>=1 && y1<=m && map1[x1][y1]=='.'){
                x = x1;
                y = y1;
                map1[x][y]='0';
                sum+=1;

            }
            else if(x1>=1 && x1<=n && y1>=1 && y1<=m && map1[x1][y1]=='0'){
                x = x1;
                y = y1;

            }
            else{
                d = (d+1)%4;
            }
        }

        cout<<sum<<endl;
    }

    return 0;
}
