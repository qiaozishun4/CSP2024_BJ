#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char map1[1007][1007];
int go(){
    int ans=1;
    while(k--){
        if(d==0){
            if(y+1<=m&&(map1[x][y+1]=='.'||map1[x][y+1]=='*')){
                y++;
                if(map1[x][y]=='.'){
                    ans++;
                    map1[x][y]='*';
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        else if(d==1){
            if(x+1<=m&&(map1[x+1][y]=='.'||map1[x+1][y]=='*')){
                x++;
                if(map1[x][y]=='.'){
                    ans++;
                    map1[x][y]='*';
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        else if(d==2){
            if(y-1>0&&(map1[x][y-1]=='.'||map1[x][y-1]=='*')){
                y--;
                if(map1[x][y]=='.'){
                    ans++;
                    map1[x][y]='*';
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        else if(d==3){
            if(x-1>0&&(map1[x-1][y]=='.'||map1[x-1][y]=='*')){
                x--;
                if(map1[x][y]=='.'){
                    ans++;
                    map1[x][y]='*';
                }
            }
            else{
                d=(d+1)%4;
            }
        }
    }
    return ans;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map1[i][j];
            }
        }
        map1[x][y]='*';
        cout<<go()<<endl;
    }
    return 0;
}