#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int vis[1010][1010];
int n,m;
bool check(int xxx,int yyy){
    if(xxx<1||xxx>n||yyy<1||yyy>m)return 0;
    if(a[xxx][yyy]=='x')return 0;
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int _;
    cin >> _;
    while(_--){
        int k,xs,ys,ds;
        cin >> n >> m >> k >> xs >> ys >> ds;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
                vis[i][j]=0;
            }
        }
        vis[xs][ys]=1;
        int res=0;
        int xj=xs,yj=ys,dj=ds;
        while(k--){
 //               cout << xj << yj << dj << endl;
            int x3=xj,y3=yj;
            if(dj==0){
                y3++;
            }
            if(dj==1){
                x3++;
            }
            if(dj==2){
                y3--;
            }
            if(dj==3){
                x3--;
            }
//            cout << xj << yj << endl;
            if(check(x3,y3)==0){
                dj=(dj+1)%4;
            }else{
//                cout << y3 << x3 << endl;
                xj=x3;
                yj=y3;
 //               cout << xj << yj << x3 << y3 << endl;
            }
            vis[xj][yj]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
