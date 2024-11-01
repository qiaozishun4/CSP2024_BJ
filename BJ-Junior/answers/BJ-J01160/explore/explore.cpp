#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    char so;
    int t,n,m,k,x,y,d,cnt=0;
    int ditu[1005][1005];
    cin>>t;
    for(int i=1;i<=t;i++){
        cnt=0;
        int dis[1005][1005]={0};
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                cin>>so;
                if(so=='.'){
                    ditu[j][p]=0;
                }else if(so=='x'){
                    ditu[j][p]=1;
                }
            }
        }
        for(int q=1;q<=k;q++){
            dis[x][y]=1;
            if(d==0){
                if(y+1<=m&&ditu[x][y+1]==0){
                    dis[x][y+1]=1;
                    y+=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if(x+1<=n&&ditu[x+1][y]==0){
                    dis[x+1][y]=1;
                    x+=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(y-1>=1&&ditu[x][y-1]==0){
                    dis[x][y-1];
                    y-=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==3){
                if(x-1>=1&&ditu[x-1][y]==0){
                    dis[x-1][y]=1;
                    x-=1;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int q=1;q<=m;q++){
                if(dis[j][q]==1){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
