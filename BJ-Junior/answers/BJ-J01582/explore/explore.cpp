#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,d,x,y;
        cin>>n>>m>>k>>x>>y>>d;
        char a[n+5][m+5];
        int b[n+5][m+5];
        b[x][y]=1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>a[i][j];
                b[i][j]=0;
            }
        }
        while(k--){
            if(d==0){
                if(y+1<=m&&a[x][y+1]=='.'){
                    y++;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
           else if(d==1){
                if(x+1<=n&&a[x+1][y]=='.'){
                    x++;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
           else if(d==2){
                if(y-1>=1&&a[x][y-1]=='.'){
                    y--;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
           else if(d==3){
                if(x-1>=1&&a[x-1][y]=='.'){
                    x--;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        int c=0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(b[i][j]==1){
                    c++;
                }
            }
        }
        cout<<c+1<<endl;
    }
    return 0;
}