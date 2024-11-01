#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,ans=0;
    cin>>t;
    for(int q=1;q<=t;q++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        a[x][y]='$';
        while(k--){
            if(d==0){
                if(a[x][y+1]!='x' && y+1<=m){
                    y++;
                    a[x][y]='$';
                    continue;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==1){
                if(a[x+1][y]!='x' && x+1<=n){
                    x++;
                    a[x][y]='$';
                    continue;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==2){
                if(a[x][y-1]!='x' && y-1>=1){
                    y--;
                    a[x][y]='$';
                    continue;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==3){
                if(a[x-1][y]!='x' && x-1>=1){
                    x--;
                    a[x][y]='$';
                    continue;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='$'){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
