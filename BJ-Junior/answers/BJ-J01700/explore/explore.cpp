#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
int n,m,t,a[10000+10][10000+10],ans,vis[10000+10][10000+10],k,cux,cuy,firx,firy,d,dici[5][10]={{0,1},{1,0},{0,-1},{-1,0}};
bool chk(int x,int y){
    if (x<1||x>n) return false;
    if (y<1||y>m) return false;
    return true;
}
void dfs(int dec,int x,int y){
    cux = x;
    cuy = y;
    int i = 0;
    ans = 1;
    vis[cux][cuy] = 1;
    while (i<k){
        while (a[cux+dici[dec][0]][cuy+dici[dec][1]]==1||chk(cux+dici[dec][0],cuy+dici[dec][1])==false){
            dec+=1;
            dec%=4;
            i+=1;
        }
        cux = cux+dici[dec][0];
        cuy = cuy+dici[dec][1];
        if (i>=k) break;
        if (vis[cux][cuy]==false&&a[cux][cuy]!=1){
            ans+=1;
            vis[cux][cuy] = true;
        }
        i+=1;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf ("%lld", &t);
    for (int i=1;i<=t;i++){
        scanf ("%d %d %d", &n, &m, &k);
        scanf ("%d %d %d", &firx, &firy, &d);
        ans = 0;
        for (int j=1;j<=n;j++){
            for (int _j=1;_j<=m;_j++){
                char ex;
                cin>>ex;
                if (ex=='x') a[j][_j] = 1;
                else a[j][_j] = 0;
                vis[j][_j] = 0;
            }
        }
        dfs(d,firx,firy);
        printf ("%d\n", ans);
    }
    return 0;
}
