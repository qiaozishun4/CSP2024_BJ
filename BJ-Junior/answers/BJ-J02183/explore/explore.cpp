#include <bits/stdc++.h>
using namespace std;
long long a[1005][1005][2];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long T;
    cin>>T;
    long long n,m,k,x,y,d;
    long long ans = 0;
    string s;
    for(int o=0;o<T;o++){
        ans = 1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j][0] = 0;
                a[i][j][1] = 0;
            }
        }
        a[x][y][1] = 1;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++){
                if(s[j-1]=='.'){
                    a[i][j][0] = 0;
                }
                if(s[j-1]=='x'){
                    a[i][j][0] = 1;
                }
            }
        }
        for(int i=0;i<k;i++){
            if(d==0){
                if(y+1>m){
                    d = 1;
                }
                else if(a[x][y+1][0]==1){
                    d = 1;
                }
                else{
                    y ++;
                }
            }
            else if(d==1){
                if(x+1>n){
                    d = 2;
                }
                else if(a[x+1][y][0]==1){
                    d = 2;
                }
                else{
                    x ++;
                }
            }
            else if(d==2){
                if(y-1<1){
                    d = 3;
                }
                else if(a[x][y-1][0]==1){
                    d = 3;
                }
                else{
                    y --;
                }
            }
            else if(d==3){
                if(x-1<1){
                    d = 0;
                }
                else if(a[x-1][y][0]==1){
                    d = 0;
                }
                else{
                    x --;
                }
            }
            if(a[x][y][1]==0){
                ans ++;
                a[x][y][1] = 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}