#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        char c[1005][1005];
        bool f[1005][1005]={false};
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        f[x][y]=true;
        while(k--){
            if(d==0){
                if(c[x][y+1]=='.'){
                    y++;
                }
                else{
                    d=(d+1)%4;
                }

            }
            else if(d==1){
                if(c[x+1][y]=='.'){
                    x++;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(c[x][y-1]=='.'){
                    y--;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==3){
                if(c[x-1][y]=='.'){
                    x--;
                }
                else{
                    d=(d+1)%4;
                }
            }
            f[x][y]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]==true)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
