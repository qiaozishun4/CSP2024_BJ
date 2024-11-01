#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,cnt,b[1010];
int a[1010][1010];
int maim(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int l=1;l<=t;l++){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                while(k != 0){
                    if(d == 0){
                        if(x>=1 && x<=n && y+1>=1 && y+1 <= m && a[x][y+1] == '.'){
                            cnt++;
                            x = x,y = y + 1;
                        }
                    }
                    if(d == 1){
                        if(x+1>=1 && x+1<=n && y>=1 && y <= m&& a[x+1][y] == '.'){
                            cnt++;
                            x = x + 1,y = y;
                        }
                    }
                    if(d == 2){
                        if(x>=1 && x<=n && y-1>=1 && y-1 <= m&& a[x][y-1] == '.'){
                            cnt++;
                            x = x,y = y - 1;
                        }
                    }
                    if(d == 3){
                        if(x-1>=1 && x-1<=n && y>=1 && y <= m&& a[x-1][y] == '.'){
                            cnt++;
                            x = x - 1,y = y;
                        }
                    }
                    else{
                        d = (d+1) % 4;
                    }
                    k--;
                }
            }
        }
        b[l] = cnt;
        cnt = 0;
    }
    for(int i=1;i<=t;i++){
        cout << b[i];
    }
    return 0;
}
