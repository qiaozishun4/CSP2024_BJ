#include<bits/stdc++.h>
using namespace std;
int t,d,n,m,x,y,b[1001][1001],k;
char a[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        int cnt=0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        b[x][y]++;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            if(d==1){
                if(a[x+1][y]=='.'&&x+1<=n){
                    x+=1;
                    b[x][y]++;
                    continue;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
            if(d==3){
                if(a[x-1][y]=='.'&&x-1>=1){
                    x-=1;
                    b[x][y]++;
                    continue;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
            if(d==0){
                if(a[x][y+1]=='.'&&y+1<=m){
                    y+=1;
                    b[x][y]++;
                    continue;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
            if(d==2){
                if(a[x][y-1]=='.'&&y-1>=1){
                    y-=1;
                    b[x][y]++;
                    continue;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]!=0)cnt++;
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
