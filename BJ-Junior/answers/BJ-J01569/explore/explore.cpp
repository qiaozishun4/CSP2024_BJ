#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char a[1000][1000];
bool flag[1000][1000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        long long ans=1;
        memset(flag,false,sizeof flag);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        flag[x][y]=true;
        for(int i=1;i<=k;i++){
            if(d==0){
                if(a[x][y+1]=='.'){
                    if(flag[x][y+1]==false){
                        ans++;
                    }
                    y++;
                    flag[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                if(a[x+1][y]=='.'){
                    if(flag[x+1][y]==false){
                        ans++;
                    }
                    x++;
                    flag[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(a[x][y-1]=='.'){
                    if(flag[x][y-1]==false){
                        ans++;
                    }
                    y--;
                    flag[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else{
                if(a[x-1][y]=='.'){
                    if(flag[x-1][y]==false){
                        ans++;
                    }
                    x--;
                    flag[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
