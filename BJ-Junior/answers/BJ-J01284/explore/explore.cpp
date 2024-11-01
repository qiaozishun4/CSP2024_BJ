#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char c[1010][1010];
bool f[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(f,0,sizeof f);
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            f[x][y]=1;
            if(d==0){
                if(c[x][y+1]=='x'||y==m){
                    d=(d+1)%4;
                }
                else y++;
            }
            else if(d==1){
                if(c[x+1][y]=='x'||x==n){
                    d=(d+1)%4;
                }
                else x++;
            }
            else if(d==2){
                if(c[x][y-1]=='x'||y==1){
                    d=(d+1)%4;
                }
                else y--;
            }
            else if(d==3){
                if(c[x-1][y]=='x'||x==1){
                    d=(d+1)%4;
                }
                else x--;
            }
        }
        f[x][y]=1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j])cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
