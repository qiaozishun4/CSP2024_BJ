#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,gx,gy;
int movex[4]={0,1,0,-1},movey[4]={1,0,-1,0};
char mp[1002][1002];
int  zg[1002][1002]={};
int place(int x,int y,int d,int step,int n,int m,int places){
    int plc=places;
    if(step==0){
        return places;
    }
    int nextx=x+movex[d],nexty=y+movey[d];
    if(1<=x+movex[d] and n>=x+movex[d] and 1<=y+movey[d] and m>=y+movey[d] and mp[nextx][nexty]!='x'){
        if(zg[nextx][nexty]!=1){ cout<<x<<"  "<<y<<"and"<<d<<"//";zg[nextx][nexty]=1;return place(nextx,nexty,d,step-1,n,m,places+1);}
        else return place(nextx,nexty,d,step-1,n,m,places);
    }else{
        d=(d+1)%4;
        if(zg[x][y]!=1){ cout<<x<<"  "<<y<<"and"<<d<<"//";zg[x][y]=1;return place(x,y,d,step-1,n,m,places+1);}
        return place(x,y,d,step-1,n,m,places);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","r",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int jx=1;jx<=m;jx++){
            for(int jy=1;jy<=n;jy++){
                cin>>mp[jx][jy];
            }
        }
        cout<<place(x,y,d,k,n,m,1);
 
    }
    return 0;
}