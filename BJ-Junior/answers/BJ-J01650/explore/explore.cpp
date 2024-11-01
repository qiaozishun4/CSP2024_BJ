#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
        char a[int(1e3)+1][int(1e3+1)];
        long long n=0,m=0,x=0,y=0,k=0,sum=1,d=0;
        cin>>n>>m>>k>>x>>y>>d;
        a[x][y]='@';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            int nx=0,ny=0;
            if(d==0){
                nx=0;
                ny=1;
            }else if(d==1){
                nx=1;
                ny=0;
            }else if(d==2){
                nx=0;
                ny=-1;
            }else{
                nx=-1;
                ny=0;
            }
            if(x+nx>n||x+nx<1||y+ny>m||y+ny<1){
                d=(d+1)%4;
            }else if(a[x+nx][y+ny]=='.'){
                sum++;
                y+=ny;
                x+=nx;
                a[x][y]='@';
            }else if(a[x+nx][y+ny]=='@'){
                y+=ny;
                x+=nx;
            }else if(a[x+nx][y+ny]=='x'){
                d=(d+1)%4;
            }

        }
        cout<<sum<<endl;
    }
    return 0;
}
