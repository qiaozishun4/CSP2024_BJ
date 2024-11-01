#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,s=0;
char c[10][10000][10000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int r=1;r<=t;r++){
        cin>>n>>m>>k>>x>>y>>d;
        s=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>c[r][i][j];
        c[r][x][y]='1';
        for(int i=1;i<=k;i++){
            if(d==0&&y+1<=m&&c[r][x][y+1]!='x'){
                y++;
                c[r][x][y]='1';
            }else if(d==1&&x+1<=n&&c[r][x+1][y]!='x'){
                x++;
                c[r][x][y]='1';
            }else if(d==2&&y-1>=1&&c[r][x][y-1]!='x'){
                y--;
                c[r][x][y]='1';
            }else if(d==3&&x-1>=1&&c[r][x-1][y]!='x'){
                x--;
                c[r][x][y]='1';
            }else
                d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(c[r][i][j]=='1')
                    s++;
        cout<<s<<endl;
    }
    return 0;
}