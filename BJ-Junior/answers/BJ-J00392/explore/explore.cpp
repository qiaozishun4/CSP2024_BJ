#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,x,y,d,tmpx,tmpy;
char mapt[1005][1005];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--){
        long long ans=0;
        bool flag[1005][1005]={0};
        cin >> n >> m >> k >> x >> y >> d;
        flag[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> mapt[i][j];
            }
        }
        while(k--){
            if(d==0){
                tmpy=y+1;
                tmpx=x;
            }else if(d==1){
                tmpx=x+1;
                tmpy=y;
            }else if(d==2){
                tmpy=y-1;
                tmpx=x;
            }else if(d==3){
                tmpx=x-1;
                tmpy=y;
            }
            if(tmpx<1||tmpx>n||tmpy<1||tmpy>m||mapt[tmpx][tmpy]=='x'){
                d=(d+1)%4;
                continue;
            }else{
                x=tmpx,y=tmpy;
                flag[x][y]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(flag[i][j]){
                    ans++;
                    //cout << i << " " << j << "\n";
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
