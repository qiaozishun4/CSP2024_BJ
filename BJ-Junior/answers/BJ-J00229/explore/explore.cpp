#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXNM=10005;
int n;//地图的行数
int m;//地图的列数
int k;//机器人执行操作的次数
bool mapp[MAXNM][MAXNM];//t=可通行.f=不可通行
bool guo[MAXNM][MAXNM];
int ma[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};//映射表
void loop(){
    scanf("%d%d%d",&n,&m,&k);
    int x0,y0,d0;
    scanf("%d%d%d",&x0,&y0,&d0);
    memset(guo,guo[MAXNM][MAXNM],0);
    /*
    for(int x=0;x<1005;x++){
        for(int y=0;y<1005;y++){
            printf("%d ",guo[x][y]);
        }
        printf("\n");
    }
    */
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            char f;
            //scanf("%s",&f);
            cin>>f;
            if(f=='.'){
                mapp[x][y]=true;
            }
            else if(f=='x'){
                mapp[x][y]=false;
            }
            else printf("err!\n");
        }
    }
    int ans=1;
    guo[x0][y0]=true;
    for(int _=0;_<k;_++){
        int x=x0+ma[d0][0],y=y0+ma[d0][1];
        if(x>0 && y>0 && x<=n && y<=m && mapp[x][y]){
            x0=x;
            y0=y;
            if(!guo[x0][y0]){
                guo[x0][y0]=true;
                ans++;
            }
        }
        else{
            d0=(d0+1)%4;
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int _=0;_<n;_++){
        loop();
    }
    return 0;
}