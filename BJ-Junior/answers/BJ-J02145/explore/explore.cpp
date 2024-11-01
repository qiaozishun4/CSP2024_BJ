#include <bits/stdc++.h>

using namespace std;

int t;
int n,m,k;
int x,y,d;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char arr[1005][1005];
bool marker[1005][1005];

int function114514(){
    int ans=1;
    marker[x][y]=true;
    for(int i=0;i<k;i++){
        int nx,ny;
        nx=x+dx[d];
        ny=y+dy[d];
        if(((1<=nx&&nx<=n)&&(1<=ny&&ny<=m))&&arr[nx][ny]=='.'){
            x=nx;
            y=ny;
            if(marker[x][y]==false){
                ans++;
                marker[x][y]=true;
            }
            //cout << x << ',' << y << endl;
        }
        else{
            d=(d+1)%4;
            //cout << "d=" << d << ' ' << (1<=nx&&nx<=n) << (1<=ny&&y<=ny) << (arr[nx][ny]=='.') << endl;
        }
    }
    return ans;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin >> arr[j][k];
                marker[j][k]=false;
            }
        }
        cout << function114514() << endl;
    }

    return 0;
}
