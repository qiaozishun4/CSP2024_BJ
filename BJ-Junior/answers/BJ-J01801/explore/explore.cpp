#include<bits/stdc++.h>
using namespace std;
int emap[1005][1005]={0};
int dir[4][2]={(0,1),(1,0),(0,-1),(-1,0)};
int n,m,k,x,y,d;
char c;
void explore(){
    while(k--){
        if(x+dir[d][0]>=1&&x+dir[d][0]<=n && y+dir[d][1]>=1&&y+dir[d][1]<=m && emap[x+dir[d][0]][y+dir[d][1]]>=1){
            x+=dir[d][0];
            y+=dir[d][1];
            emap[x][y]++;
        }else{
            d=(d+1)%4;
        }
    }
    int num=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(emap[i][j]>1){
                num++;
                emap[i][j]=0;
            }
        }
    }
    cout<<num<<endl;
    return;
}
int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>c;
                if(c=='.')emap[i][j]=1;
            }
        }
        emap[x][y]++;
        explore();
    }
    return 0;
}
