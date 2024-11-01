#include<bits/stdc++.h>
using namespace std;

int T;
const int xx[]={0,1,0,-1};
const int yy[]={1,0,-1,0};
bool dt[1005][1005];
bool dao[1005][1005][4];
char c;

bool check(int i,int j){
    if(dao[i][j][0]+dao[i][j][1]+dao[i][j][2]+dao[i][j][3])
    return 1;
    return 0;
}

void mian(){
    int n,m,k,x,y,d,cnt=0;
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=0;i<=n+1;++i){
        dt[i][0]=dt[i][m+1]=0;
    }
    for(int i=0;i<=m+1;++i){
        dt[0][i]=dt[n+1][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>c;
            if(c=='.') dt[i][j]=1;
            else dt[i][j]=0;
            dao[i][j][0]=dao[i][j][1]=dao[i][j][2]=dao[i][j][3]=0;
        }
    }
    dao[x][y][d]=1;
    cnt++;
    for(int i=0;i<k;++i){
        if(dt[x+xx[d]][y+yy[d]]){
            x+=xx[d];
            y+=yy[d];
        }
        else{
            d++;
            d%=4;
        }
        if(!check(x,y)){
            cnt++;
        }
        if(dao[x][y][d]){
            break;
        }
        else{
            dao[x][y][d]=1;
        }
    }
    cout<<cnt<<"\n";
    return;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        mian();
    }
    return 0;
}
