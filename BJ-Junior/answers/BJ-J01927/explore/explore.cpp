#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
const int K = 1e6 + 9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,k,x,y,d;
char c[N][N];
bool f[N][N];

bool ch(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]!='x';
}

void Main(){

    memset(f,false,sizeof(f));

    cin>>n>>m>>k;
    cin>>x>>y>>d;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>c[i][j];
        }
    }


    int ans=1;

    f[x][y]=true;

    for(int i=1;i<=k;++i){

        if(!ch(x+dx[d],y+dy[d])){
            d=(d+1)%4;
            continue;
        }

        x=x+dx[d];
        y=y+dy[d];

        if(!f[x][y]&&c[x][y]!='x'){
            ans++;
            f[x][y]=true;
        }

    }

    cout<<ans<<endl;

}

int main(){


    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        Main();
    }

    return 0;
}