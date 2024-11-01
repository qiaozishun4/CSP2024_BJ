#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1010;
const int go[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int visited[N][N];
char data[N][N];
int n,m,k,x,y,d,num;
void run() {
    if(data[x+go[d][0]][y+go[d][1]]=='.') {
        if(1<=x+go[d][0]&&x+go[d][0]<=n&&1<=y+go[d][1]&&y+go[d][1]<=m) {
            x+=go[d][0];
            y+=go[d][1];
            if(visited[x][y]==0) {
                visited[x][y]=1;
                num++;
            }
        }
        else {
            d=(d+1)%4;
        }
    }
    else {
        d=(d+1)%4;
    }
}
void fun() {
    num=1;
    memset(visited,0,sizeof(visited));
    memset(data,0,sizeof(data));
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    visited[x][y]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>data[i][j];
        }
    }
    for(int i=0;i<k;i++) run();
    cout<<num<<endl;
}
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;

    cin>>t;
    for(int i=0;i<t;i++) fun();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
