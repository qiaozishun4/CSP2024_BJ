#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin>>T;
    for(int q=1;q<=T;q++){
        int n, m, k, x, y, d, ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                if(a[x][y+1]=='.'){
                    y+=1;
                    a[x][y]='0';
                    ans++;
                }else if(a[x][y+1]=='0'){
                    y+=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if(a[x+1][y]=='.'){
                    x+=1;
                    a[x][y]='0';
                    ans++;
                }else if(a[x+1][y]=='0'){
                    x+=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(a[x][y-1]=='.'){
                    y-=1;
                    a[x][y]='0';
                    ans++;
                }else if(a[x][y-1]=='0'){
                    y-=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==3){
                if(a[x-1][y]=='.'){
                    x-=1;
                    a[x][y]='0';
                    ans++;
                }else if(a[x-1][y]=='0'){
                    x-=1;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<ans;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=' ';
            }
        }
    }
    return 0;
}
