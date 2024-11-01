#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
int t=0;
cin>>t;
while(t--){
    int m=0,n=0,k=0;
    cin>>n>>m>>k;
    int x=0,y=0,d=0;
    cin>>x>>y>>d;
    x--;y--;
    char cmap[n][m];
    int imap[n][m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cmap[i][j];
        }
    }imap[x][y]=1;
    while(k--){

        if(d==0){
                if(y+1<m&&cmap[x][y+1]=='.'){
                        y++;
                }
                else {
                        d=1;

                }
        }else if(d==1){
            if(x+1<n&&cmap[x+1][y]=='.'){
                        x++;
                }
                else {
                        d=2;
                }
        }else if(d==2){
            if(y-1>=0&&cmap[x][y-1]=='.'){
                        y--;
                }
                else {
                        d=3;
                }
        }else if(d==3){
            if(x-1>=0&&cmap[x-1][y]=='.'){
                        x--;
                }
                else {
                        d=0;
        }

    }
    imap[x][y]=1;
    }
    int zn=0;
    for(int ix=0;ix<m;ix++){
        for(int jx=0;jx<n;jx++){
            if(imap[jx][ix]==1)zn++;
        }
    }
    cout<<zn<<endl;
}


return 0;
}