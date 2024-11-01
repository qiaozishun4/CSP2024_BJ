#include <bits/stdc++.h>
using namespace std;

int t;
int n,m,k;
int d1,d2,d;

char map1[10001][10001]={};
bool vis1[10001][10001]={};

void init(){
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            vis1[i][j]=0;
        }
    }
}

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

void f(int y,int x,int v){
    if (v>k){
        return;
    }

    for (int i=0;i<3;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if (xx>=0&&xx<m&&yy>=0&&yy<n&&map1[yy][xx]=='.'&&vis1[yy][xx]==0){
            vis1[yy][xx]=1;
            if (i!=d){
                d=(d+i)%4;
                if (d==0){
                    dx[0]=1;dx[1]=0;dx[2]=-1;dx[3]=0;
                    dy[0]=0;dy[1]=1;dy[2]=0;dy[3]=-1;
                }
                if (d==1){
                    dx[0]=0;dx[1]=-1;dx[2]=0;dx[3]=1;
                    dy[0]=1;dy[1]=0;dy[2]=-1;dy[3]=0;
                }
                if (d==2){
                    dx[0]=-1;dx[1]=0;dx[2]=1;dx[3]=0;
                    dy[0]=0;dy[1]=-1;dy[2]=0;dy[3]=1;
                }
                if (d==3){
                    dx[0]=0;dx[1]=1;dx[2]=0;dx[3]=-1;
                    dy[0]=-1;dy[1]=0;dy[2]=1;dy[3]=0;
                }
                v++;
            }
            f(yy,xx,v+1);
            return;
        }
        v++;
    }
}

int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;

    for (int i=0;i<t;i++){
        cin>>n>>m>>k;
        cin>>d1>>d2>>d;
        init();
        for (int j=0;j<n;j++){
            for (int jj=0;jj<m;jj++){
                cin>>map1[j][jj];
            }
        }

        if (d==0){
            dx[0]=1;dx[1]=0;dx[2]=-1;dx[3]=0;
            dy[0]=0;dy[1]=1;dy[2]=0;dy[3]=-1;
        }
        if (d==1){
            dx[0]=0;dx[1]=-1;dx[2]=0;dx[3]=1;
            dy[0]=1;dy[1]=0;dy[2]=-1;dy[3]=0;
        }
        if (d==2){
            dx[0]=-1;dx[1]=0;dx[2]=1;dx[3]=0;
            dy[0]=0;dy[1]=-1;dy[2]=0;dy[3]=1;
        }
        if (d==3){
            dx[0]=0;dx[1]=1;dx[2]=0;dx[3]=-1;
            dy[0]=-1;dy[1]=0;dy[2]=1;dy[3]=0;
        }
        vis1[d1-1][d2-1]=1;
        f(d1-1,d2-1,1);

        int sum=0;
        for (int ii=0;ii<n;ii++){
            for (int j=0;j<m;j++){
                if (vis1[ii][j]){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
