#include<bits/stdc++.h>
using namespace std;
int t;
int n[6],m[6],k[6];
int xo,yo,d0;
int vis[1005][1005],flag,day,sum,I;
char s[1005][1005];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
void dfs(int x,int y){
    if(day==k[I]){
        return ;
    }
    vis[xo][yo]=1;
    for(int i=0;i<4;i++){
        int xx,yy;
        if(d0==0){
            xx=x+dir[i][0];
            yy=y+dir[i][1];
        }
        else if(d0==1){
            xx=x+dir[i][1];
            yy=y+dir[i][0];
        }
        else if(d0==2){
            xx=x+dir[i][0];
            yy=y+dir[i][-1];
        }
        else if(d0==3){
            xx=x+dir[i][-1];
            yy=y+dir[i][0];
        }
        if(xx>n[I]||yy>m[I]||xx<1||yy<1||vis[xx][yy]==1||s[xx][yy]=='x'){
            if(d0==0){
                xx=x+dir[i][0];
                yy=y+dir[i][-1];
            }
            else if(d0==1){
                xx=x+dir[i][-1];
                yy=y+dir[i][0];
            }
            else if(d0==2){
                xx=x+dir[i][0];
                yy=y+dir[i][1];
            }
            else if(d0==3){
                xx=x+dir[i][1];
                yy=y+dir[i][0];
            }
            d0=(d0+1)%4;
            day=day+1;
            continue;
        }
        else{
            vis[xx][yy]=1;
            day=day+1;
            sum=sum+1;
            dfs(xx,yy);
        }
        if(day==k[I]){
            return ;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>m[i]>>k[i]>>xo>>yo>>d0;
        for(int j=1;j<=n[i];j++){
            for(int l=1;l<=m[i];l++){
                cin>>s[j][l];
            }
        }
        int I=i;
        dfs(xo,yo);
        cout<<sum<<endl;
        sum=0;
        day=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

