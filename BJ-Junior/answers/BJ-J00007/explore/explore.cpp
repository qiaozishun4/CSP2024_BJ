#include<bits/stdc++.h>
using namespace std;
char b[1002][1002];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,xa,xb,xc,cnt=1;
        cin>>n>>m>>k>>xa>>xb>>xc;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>b[i][j];
        }
        int headx=xa,heady=xb;
        b[xa][xb]=1;
        while(k--){
            if(xc==0){
                if(heady+1<=m&&(b[headx][heady+1]=='.'||b[headx][heady+1]==1)){
                    heady++;
                    if(b[headx][heady]!=1){
                        cnt++;
                        b[headx][heady]=1;
                    }
                }else xc=(xc+1)%4;
            }else if(xc==1){
                if(headx+1<=n&&(b[headx+1][heady]=='.'||b[headx+1][heady]==1)){
                    headx++;
                    if(b[headx][heady]!=1){
                        cnt++;
                        b[headx][heady]=1;
                    }
                }else xc=(xc+1)%4;
            }else if(xc==2){
                if(heady-1>=1&&(b[headx][heady-1]=='.'||b[headx][heady-1]==1)){
                    heady--;
                    if(b[headx][heady]!=1){
                        cnt++;
                        b[headx][heady]=1;
                    }
                }else xc=(xc+1)%4;
            }else{
                if(headx-1>=1&&(b[headx-1][heady]=='.'||b[headx-1][heady]==1)){
                    headx--;
                    if(b[headx][heady]!=1){
                        cnt++;
                        b[headx][heady]=1;
                    }
                }else xc=(xc+1)%4;
            }
        }
        cout<<cnt<<'\n';

    }
    return 0;
}
