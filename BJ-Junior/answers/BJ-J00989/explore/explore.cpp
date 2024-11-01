#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
int ans=1;
int t,n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) scanf("%c",&a[i][j]);
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                if(a[x][y+1]=='.'){
                    ans++;
                    y++;
                    continue;
                }
                else{
                    if(i==1) ans++;
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==1){
                if(a[x+1][y]=='.'){
                    ans++;
                    x++;
                    continue;
                }
                else{
                    if(i==1) ans++;
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==2){
                if(a[x][y-1]=='.'){
                    ans++;
                    y--;
                    continue;
                }
                else{
                    if(i==1) ans++;
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==3){
                if(a[x-1][y]=='.'){
                    ans++;
                    x--;
                    continue;
                }
                else{
                    if(i==1) ans++;
                    d=(d+1)%4;
                    continue;
                }
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
