#include <bits/stdc++.h>
using namespace std;
int t,x=0,y=0,d=0,k=0,n=0,m=0;
char table[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(1){
        if(t==0)break;
        t--;
        int ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>table[i][j];
            }
        }
        table[x][y]='#';
        for(int i=0;i<k;i++){
            int newx,newy;
            if(d==0){
                newx=x;
                newy=y+1;
            }
            if(d==1){
                newx=x+1;
                newy=y;
            }
            if(d==2){
                newx=x;
                newy=y-1;
            }
            if(d==3){
                newx=x-1;
                newy=y;
            }
            if(1<=newx&&1<=newy&&newx<=n&&newy<=m&&table[newx][newy]!='x'){
                x=newx;y=newy;
                table[x][y]='#';
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(table[i][j]=='#')ans++;
                //cout<<table[i][j];
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}