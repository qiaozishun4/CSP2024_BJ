#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;cin>>T;
    while(T--){
        int n,m,k;cin>>n>>m>>k;
        int x,y,d;cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>c[i][j];
        }
        /*int cnt=0;
        for(int i=1;i<=k;i++){
            int next_x=x,next_y=y;
            bool flag;
            if(d==0)next_x=x,next_y=y+1;
            if(d==1)next_x=x+1,next_y=y;
            if(d==2)next_x=x,next_y=y-1;
            if(d==3)next_x=x-1,next_y=y;
            if(1<=next_x&&next_x<=n&&1<=next_y&&next_y<=m&&c[next_x][next_y]=='.')flag=true;
            else flag=false;
            if(i==1&&!flag)cnt++;
            if(flag){
                x=next_x,y=next_y;
                cnt++;
            }else d=(d+1)%4;
        }
        cout<<cnt<<'\n';*/
        int next_x,next_y;
        if(d==0)next_x=x,next_y=y+1;
        if(d==1)next_x=x+1,next_y=y;
        if(d==2)next_x=x,next_y=y-1;
        if(d==3)next_x=x-1,next_y=y;
        if(1<=next_x&&next_x<=n&&1<=next_y&&next_y<=m&&c[next_x][next_y]=='.')cout<<2<<'\n';
        else cout<<1<<'\n';
    }
    return 0;
}
