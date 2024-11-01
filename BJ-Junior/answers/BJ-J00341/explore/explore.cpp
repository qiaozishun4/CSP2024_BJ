#include<bits/stdc++.h>
using namespace std;
char board[1050][1050];
bool jg[1050][1050];
int x,y,d,k,t,n,m;
bool inboard(int xx,int yy){
    if(xx>=1&&xx<=n){
        if(yy>=1&&yy<=m){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                jg[i][j]=0;
                cin>>board[i][j];
            }
        }

        for(int timesk=0;timesk<k;timesk++){
            //cout<<timesk+1<<' '<<x<<' '<<y<<endl;
            //for(int i=1;i<=n;i++){
            //    for(int j=1;j<=m;j++){
             //       cout<<jg[i][j]<<' ';
            //    }
            //    cout<<endl;
            //}
            jg[x][y]=1;
            if(d==0){
                if(board[x][y+1]!='x'&&inboard(x,y+1)){//n
                    y++;
                }else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                if(board[x+1][y]!='x'&&inboard(x+1,y)){//e
                    x++;
                }else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(board[x][y-1]!='x'&&inboard(x,y-1)){//s
                    y--;
                }else{
                    d=(d+1)%4;
                }
            }
            else if(d==3){
                if(board[x-1][y]!='x'&&inboard(x-1,y)){//w
                    x--;
                }else{
                    d=(d+1)%4;
                }
            }
            jg[x][y]=1;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cnt+=jg[i][j];
                //cout<<jg[i][j]<<' ';
            }
            //cout<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
