#include<bits/stdc++.h>
using namespace std;
char a[1005][1005],b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    cin >>t;
    while(t--){
        int cnt=0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        b[x][y]='1';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        while(k--){
            if(d==0){
                y++;
                if(x<1 || x>n || y<1 || y>m || a[x][y]=='x'){
                    y--;
                    d=(d+1)%4;
                }else{
                    b[x][y]='1';
                }
            }else if(d==1){
                x++;
                if(x<1 || x>n || y<1 || y>m || a[x][y]=='x'){
                    x--;
                    d=(d+1)%4;
                }else{
                    b[x][y]='1';
                }
            }else if(d==2){
                y--;
                if(x<1 || x>n || y<1 || y>m || a[x][y]=='x'){
                    y++;
                    d=(d+1)%4;
                }else{
                    b[x][y]='1';
                }
            }else if(d==3){
                x--;
                if(x<1 || x>n || y<1 || y>m || a[x][y]=='x'){
                    x++;
                    d=(d+1)%4;
                }else{
                    b[x][y]='1';
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]=='1'){
                    cnt++;
                }
                b[i][j]='0';
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

