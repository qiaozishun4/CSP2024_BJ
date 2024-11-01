#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int x,y,d;
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
const int kMax=1e3;
char datas[kMax+5][kMax+5];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>datas[i][j];
            }
        }
        datas[x][y]='!';
        while(k--){
            int tmpx=x+dx[d];
            int tmpy=y+dy[d];
            if(tmpx<1||tmpx>n||tmpy<1||tmpy>m){
                d=(d+1)%4;
            }else if(datas[tmpx][tmpy]=='x'){
                d=(d+1)%4;
            }else{
                x=tmpx;
                y=tmpy;
                datas[x][y]='!';
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(datas[i][j]=='!'){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
