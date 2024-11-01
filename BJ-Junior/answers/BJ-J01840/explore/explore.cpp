#include <bits/stdc++.h>
using namespace std;
int x,y,k,ans=0,t,d,m,n;
bool a[1005][1005],b[1005][1005];
void f(){
    int nx=x,ny=y;
    if(d==0){
        ny++;
    }else if(d==1){
        nx++;
    }else if(d==2){
        ny--;
    }else if(d==3){
        nx--;
    }
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==0){
        x=nx,y=ny;
        if(b[x][y]==0){
            ans++;
            b[x][y]=1;
        }
    }else{
        d=(d+1)%4;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        char c;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin >> c;
                b[j][k]=0;
                if(c=='.'){
                    a[j][k]=0;
                }else{
                    a[j][k]=1;
                }
            }
        }
        ans=1,b[x][y]=1;
        for(int j=1;j<=k;j++){
            f();
        }
        cout << ans << "\n";
    }
    return 0;
}
