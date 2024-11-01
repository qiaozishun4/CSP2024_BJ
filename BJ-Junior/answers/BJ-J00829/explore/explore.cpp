#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >>T;
    while(T--){
        int n,m,k;
        int ans=1;
        cin >>n>>m>>k;
        char a[1001][1001];
        int x,y,d;
        cin >>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cin >>a[i][j];
        }
        for(int i=1;i<=k;i++){
            bool f=1;
            int nx=x,ny=y;
            if(d == 0)ny+=1;
            else if(d == 1) nx+=1;
            else if(d == 2) ny-=1;
            else nx-=1;
            if(a[nx][ny] == '.') ans++,a[nx][ny] = 1;
            else if(a[nx][ny] != 1) d++,f=0;
            if(d == 4) d = 0;
            if(f == 1) x=nx,y=ny;
        }
        cout <<ans<<endl;
    }
    return 0;
}
