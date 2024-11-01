#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,s=1;cin>>t;
    for(int i=0;i<t;i++){
        s=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>c[j][l];
            }
        }
        for(int j=0;j<k;j++){
            if(d==0){
                if(y+1<=m&&c[x][y+1]=='.'){
                    y++;
                    s++;
                    continue;
                }
                else {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==1){
                if(x+1<=n&&c[x+1][y]=='.'){
                    x++;
                    s++;
                    continue;
                }
                else {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==2){
                if(y-1<=n&&c[x][y-1]=='.'){
                    y--;
                    s++;
                    continue;
                }
                else {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==3){
                if(x-1<=n&&c[x-1][y]=='.'){
                    x--;
                    s++;
                    continue;
                }
                else {
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
