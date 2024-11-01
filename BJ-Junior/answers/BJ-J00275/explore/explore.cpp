//BJ-00275 LMX BJ12Z Grade 8 Class 1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
char a[1145][1419];
bool v[1145][1419];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j],v[i][j]=false;

        int ans=1;
        v[x][y]=1;
        while(k--){
            int xx=x+dir[d][0];
            int yy=y+dir[d][1];
            if(xx<1||n<xx||yy<1||m<yy||a[xx][yy]=='x')d=(d+1)%4;
            else{
                if(!v[xx][yy])ans++,v[xx][yy]=1;
                x=xx,y=yy;
            }
            //printf("(%d,%d) d=%d\n",x,y,d);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

*/
