#include <bits/stdc++.h>
using namespace std;
struct RBPos{
    int x,y;
    int d;
    int i;
};
int n,m,k;
char Map[1005][1005];
bool visited[1005][1005];

RBPos movePos(RBPos Last){
    RBPos result;
    if(Last.d==0){
        result.x=Last.x;
        result.y=Last.y+1;
    }
    else if(Last.d==1){
        result.x=Last.x+1;
        result.y=Last.y;
    }
    else if(Last.d==2){
        result.x=Last.x;
        result.y=Last.y-1;
    }
    else if(Last.d==3){
        result.x=Last.x-1;
        result.y=Last.y;
    }
    result.d=Last.d;
    return result;
}

RBPos walk(RBPos now){
    RBPos result;
    RBPos Use=now;
    result=movePos(Use);
    for(int i=0;i<4;i++){
        if((result.x>=1)&&(result.x<=n)&&(result.y>=1)&&(result.y<=m)&&(Map[result.x][result.y]=='.')){
            result.i=i;
            return result;
        }
        Use.d=(Use.d+1)%4;
        result=movePos(Use);
    }
    return now;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int a=0;a<T;a++){
        RBPos Start;
        int ans=0;
        memset(visited,0,sizeof(visited));
        cin>>n>>m>>k;
        cin>>Start.x>>Start.y>>Start.d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>Map[i][j];
            }
        }
        visited[Start.x][Start.y]=true;
        for(int i=0;i<k;i++){
            Start=walk(Start);
            i=i+Start.i;
            if(i<k){
                visited[Start.x][Start.y]=true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(visited[i][j]==true){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}