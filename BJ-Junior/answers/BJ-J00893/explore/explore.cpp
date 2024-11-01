#include<iostream>
#include<cstdio>
using namespace std;
int t;
long long f[10005][10005],v[10005][10005];//f地图v是走过的点
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,a;//地图大小，步数
    int x,y,d,ans=1;//d是方向
    cin>>t;
    for(int k=1;k<=t;k++){//k次输入不同图
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        v[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<m;j++){
                cin>>f[i][j];
            }
        }//输入地图上的点
        for(int i=a;i>0;i--){//步数减少
        if(d=0&&f[x+1][y]=="."&&v[x+1][y]==0){//东
            ans++;
            x++;//改坐标
            v[x][y]=1;
        }//是空地
        else{
            d++;
        }//转向
        if(d=1&&f[x][y-1]=="."&&v[x][y-1]==0){//南
            ans++;
            y--;//改坐标
            v[x][y]=1;
        }
        else{
            d++;
        }
        if(d=2&&f[x-1][y]=="."&&v[x-1][y]==0){//西
            ans++;
            x--;//改坐标
            v[x][y]=1;
        }
        else{
            d++;
        }
        if(d=3&&f[x][y+1]=="."&&v[x][y+1]==0){//北
            ans++;
            y++;//改坐标
            v[x][y]=1;
        }
        else{
            d=0;//北回到东
        }}//转向走路就没了
        cout<<ans;//输出当前已走点
        ans=1;//重置
    }
    return 0;
}
