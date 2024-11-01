#include<bits/stdc++.h>
using namespace std;
string g[1005];
int flag[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset (flag,0,sizeof(flag));
        int n,m,k;
        cin>>n>>m>>k;
        //各种输入
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        for(int i=0;i<n;i++){
            cin>>g[i];
        }
        x0--,y0--;
        int cnt=1;
        flag[x0][y0]=true;
        while(k--){
            //执行一次操作
            //flag表示 1：向右转，0：前进一步
            int nx=x0+dx[d0];
            int ny=y0+dy[d0];
            if(nx<0||ny<0||nx>=n||ny>=m||g[nx][ny]=='x') d0=(d0+1)%4;
            else{
                if(flag[nx][ny]==0) cnt++; // 该位置没有被访问过所以++
                flag[nx][ny]=1;
                x0=nx,y0=ny;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}