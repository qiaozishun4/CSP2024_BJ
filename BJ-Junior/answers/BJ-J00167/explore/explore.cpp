#include <bits/stdc++.h>
using namespace std;
int  main (){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n,m,k,x,y,d,c=0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        char a[1005][1005];
        int aa[1005][1005];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j] ;
                aa[i][j]=0;
            }
        }
        int cnt=1;
        int xx=x;
        int yy=y;
        while(k--){
            if(d==0){
                if(y+1<=m&&a[x][y+1]=='.'){
                    //cout << x << "," <<y <<"->" << x << "," << y+1 << endl;
                    y++;
                    cnt++;
                    aa[x][y]=1;
                }else{
                    //cout << "zhuan" << endl;
                    if(d!=3){
                        d++;
                    }else{
                        d=0;
                    }
                }
            }else if(d==1){
                if(x+1<=n&&a[x+1][y]=='.'){
                    //cout << x << "," <<y <<"->" << x+1 << "," << y << endl;
                    x++;
                    cnt++;
                    aa[x][y]=1;
                }else{
                    //cout << "zhuan" << endl;
                    if(d!=3){
                        d++;
                    }else{
                        d=0;
                    }
                }
            }else if(d==2){
                if(y-1>=1&&a[x][y-1]=='.'){
                    //cout << x << "," <<y <<"->" << x << "," << y-1 << endl;
                    y--;
                    cnt++;
                    aa[x][y]=1;
                }else{
                    //cout << "zhuan" << endl;
                    if(d!=3){
                        d++;
                    }else{
                        d=0;
                    }
                }
            }else if(d==3){
                if(x-1>=1&&a[x-1][y]=='.'){
                    //cout << x << "," <<y <<"->" << x-1 << "," << y << endl;
                    x--;
                    cnt++;
                    aa[x][y]=1;
                }else{
                    //cout << "zhuan" << endl;
                    if(d!=3){
                        d++;
                    }else{
                        d=0;
                    }
                }
            }
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(aa[i][j]==1){
                    cnt++;
                }
            }
        }
        if(aa[xx][yy]==1)
        cout << cnt <<endl;
        else
        cout << cnt+1 <<endl;
        //3
      //2   0
        //1
    }
    return 0;
}
