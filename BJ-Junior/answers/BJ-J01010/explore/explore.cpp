#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
char arr[1005][1005];
int to[4][2]={0,1,1,0,0,-1,-1,0};
bool bo[1005][1005];
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
    int t;

    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int x,y,o;
        cin>>x>>y>>o;
        bo[x][y]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
            }
        }
        while(k--){
            int tx=x+to[o][0];
            int ty=y+to[o][1];
            if(tx>0&&tx<=n&&ty>0&&ty<=m&&arr[tx][ty]=='.'){
                x=tx,y=ty;
                bo[tx][ty]=true;
            }else{
                o=(o+1)%4;
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(bo[i][j]) sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}