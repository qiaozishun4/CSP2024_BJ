#include<bits/stdc++.h>
using namespace std;
int mp[1000][1000];
int vis[1000][1000];
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int d;
bool cp(int x,int y){
    if(mp[x+dis[d][0]][y+dis[d][1]]==1) return true;
    return false;
}
int n;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        memset(mp,0,sizeof mp);
        memset(vis,0,sizeof vis);
        int x,y,k;
        cin>>x>>y>>k;
        int nx,ny;
        cin>>nx>>ny>>d;
        vis[nx][ny]=1;
        int ct=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                char p;
                cin>>p;
                if(p=='.') mp[i][j]=1;
                else mp[i][j]=0;
            }
        }
        for(int i=k;i--;i>0){
            if(cp(nx,ny)){
                int mx=nx+dis[d][0];
                int my=ny+dis[d][1];
                if(vis[mx][my]==0){
                    ct++;
                    vis[mx][my]=1;
                    nx=mx;
                    ny=my;
                } else{
                    nx=mx;
                    ny=my;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ct<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
