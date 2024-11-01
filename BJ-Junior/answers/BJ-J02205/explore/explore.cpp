#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long n,m,k,x,y,ans=0;
        int d;
        cin>>n>m>>k>>x>>y>>d;
        char l[n+1][m+1];
        bool map[n+1][m+1]={0};
        for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)cin>>l[j][k];
        for(int j=0;j<k;j++){
            if(d==0 && y+1<=m){
                if(l[x][y+1]=='.'){
                    y++;
                    if(map[x][y]==0)ans++;
                    map[x][y]==1;
                }
                else d=(d+1)%4;
            }
            else if(d==0 && y+1>m)d=(d+1)%4;
            else if(d==1 && x+1<=n){
                if(l[x+1][y]=='.'){
                    x++;
                    if(map[x][y]==0)ans++;
                    map[x][y]==1;
                }
                else d=(d+1)%4;
            }
            else if(d==1 && x+1>n)d=(d+1)%4;
            else if(d==2 && y-1>=1){
                if(l[x][y-1]=='.'){
                    y--;
                    if(map[x][y]==0)ans++;
                    map[x][y]==1;
                }
                else d=(d+1)%4;
            }
            else if(d==2 && y-1<1)d=(d+1)%4;
            else if(d==3 && x-1>=1){
                if(l[x-1][y]=='.'){
                    x--;
                    if(map[x][y]==0)ans++;
                    map[x][y]==1;
                }
                else d=(d+1)%4;
            }
            else if(d==3 && x-1<1)d=(d+1)%4;
        }
    cout<<ans;
    return 0;
}