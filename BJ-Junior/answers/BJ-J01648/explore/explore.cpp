#include<iostream>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,x,y,d;
        char a[1005][1005]={};
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int z=1;z<=m;z++){
                cin>>a[j][z];
            }
        }
        long long cnt=1;
        a[x][y]='0';
        for(int j=1;j<=k;j++){
            if(d==0){
                if(x<=n&&x>=1&&y+1>=1&&y+1<=m&&a[x][y+1]=='.'){
                    y++;
                    cnt++;
                    a[x][y]='0';
                    continue;
                }
                if(x<=n&&x>=1&&y+1>=1&&y+1<=m&&a[x][y+1]=='0'){
                    y++;
                    continue;
                }
                d=(d+1)%4;
                continue;
            }
            if(d==1){
                if(x+1<=n&&x+1>=1&&y>=1&&y<=m&&a[x+1][y]=='.'){
                    x++;
                    cnt++;
                    a[x][y]='0';
                    continue;
                }
                if(x+1<=n&&x+1>=1&&y>=1&&y<=m&&a[x+1][y]=='0'){
                    x++;
                    continue;
                }
                d=(d+1)%4;
                continue;
            }
            if(d==2){
                if(x<=n&&x>=1&&y-1>=1&&y-1<=m&&a[x][y-1]=='.'){
                    y--;
                    cnt++;
                    a[x][y]='0';
                    continue;
                }
                if(x<=n&&x>=1&&y-1>=1&&y-1<=m&&a[x][y-1]=='0'){
                    y--;
                    continue;
                }
                d=(d+1)%4;
                continue;
            }
            if(d==3){
                if(x-1<=n&&x-1>=1&&y>=1&&y<=m&&a[x-1][y]=='.'){
                    x--;
                    cnt++;
                    a[x][y]='0';
                    continue;
                }
                if(x-1<=n&&x-1>=1&&y>=1&&y<=m&&a[x-1][y]=='0'){
                    x--;
                    continue;
                }
                d=(d+1)%4;
                continue;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

