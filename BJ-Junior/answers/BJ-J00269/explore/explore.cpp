#include<iostream>

using namespace std;

const int MAXN=1e3+10,MAXM=1e3+10,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool flag[MAXN][MAXM],map[MAXN][MAXM];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;

    while(T--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char t;
                cin>>t;
                map[i][j]=(t=='.');
            }
        }
        while(k--){
            flag[x][y]=true;
            int tx=x+dx[d],ty=y+dy[d];
            if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&map[tx][ty]){
                x=tx;
                y=ty;
            }else{
                d=(d+1)%4;
            }
        }
        flag[x][y]=true;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(flag[i][j])cnt++;
                flag[i][j]=false;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
