#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d;
    cin>>T;
    while(T--){
        int cnt=0;
        cin>>n>>m>>k>>x>>y>>d;
        char c;
        bool ma[n+2][m+2],g[n+2][m+2]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='.'){
                    ma[i][j]=1;
                }else{
                    ma[i][j]=0;
                }
            }
        }
        while(k--){
            g[x][y]=1;
            int newx=x,newy=y;
            if(d==0) newy++;
            if(d==1) newx++;
            if(d==2) newy--;
            if(d==3) newx--;
            if(1<=newx&&newx<=n&&1<=newy&&newy<=m&&ma[newx][newy]){
                x=newx;
                y=newy;
                g[x][y]=1;
            }else{
                d=(d+1)%4;
            }
            g[x][y]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(g[i][j]) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
