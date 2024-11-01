#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d,s=0;
        char c[1010][1010];
        bool b[1010][1010];
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                b[i][j]=0;
                cin>>c[i][j];
            }
        }
        while(k>=0){
            k--;
            b[x][y]=1;
            if(d==0){
                if(c[x][y+1]=='.' && y+1<=m){
                    y++;
                }
                else{
                    d=(d+1)%4;
                }
                continue;
            }
            else if(d==1){
                if(c[x+1][y]=='.' && x+1<=n){
                    x++;
                }
                else{
                    d=(d+1)%4;
                }
                continue;
            }
            else if(d==2){
                if(c[x][y-1]=='.' && y-1>=1){
                    y--;
                }
                else{
                    d=(d+1)%4;
                }
                continue;
            }
            else{
                if(c[x-1][y]=='.' && x-1>=1){
                    x--;
                }
                else{
                    d=(d+1)%4;
                }
                continue;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==1)s++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
