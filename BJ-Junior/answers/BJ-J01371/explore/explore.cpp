#include<iostream>
#include<cstring>
using namespace std;
char c[1005][1005];
int h[1005][1005];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x0,y0,d0;
        cin>>n>>m>>k>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        int x=x0,y=y0,d=d0;
        while(k--){
            int nx,ny;
            if(d==0){
                nx=x;
                ny=y+1;
            }
            if(d==1){
                nx=x+1;
                ny=y;
            }
            if(d==2){
                nx=x;
                ny=y-1;
            }
            if(d==3){
                nx=x-1;
                ny=y;
            }
            if(nx<1 || nx>n || ny<1 || ny>m || c[nx][ny]=='x') d=(d+1)%4;
            else{
                h[x][y]++;
                x=nx;
                y=ny;
                h[x][y]++;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(h[i][j]) cnt++;
            }
        }
        cout<<cnt<<'\n';
        memset(h,0,sizeof(h));
    }
    return 0;
}

//finish time: 9:09
//luogu uid 453759
//BJ-J01371
//qwqawa
//IAKIOI
