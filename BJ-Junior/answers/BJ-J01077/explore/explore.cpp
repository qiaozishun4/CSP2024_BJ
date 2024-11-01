#include <bits/stdc++.h>
using namespace std;
int t,n,m,x,y,d,k;
char zb[1005][1005];
int main(){
    ios::sync_with_stdio(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int c=1;c<=t;c++){
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>zb[i][j];
            }
        }
        while(k>0){
        int yn=0;
        if(d==0 and yn==0){
            if(y+1<1 or y+1>m or zb[x][y+1]=='x'){
                d=(d+1)%4;
            }
            else{
                y++;
                ans++;
                if(zb[x][y]==0){
                    ans--;
                }
                zb[x][y]=0;
            }
            yn++;
        }
        else if(d==1 and yn==0){
            if(x+1<1 or x+1>n or zb[x+1][y]=='x'){
                d=(d+1)%4;
            }
            else{
                x++;
                ans++;
                if(zb[x][y]==0){
                    ans--;
                }
                zb[x][y]=0;
            }
            yn++;
        }
        else if(d==2 and yn==0){
            if(y-1<1 or y-1>m or zb[x][y-1]=='x'){
                d=(d+1)%4;
            }
            else{
                y--;
                ans++;
                if(zb[x][y]==0){
                    ans--;
                }
                zb[x][y]=0;
            }
            yn++;
        }
        else if(d==3 and yn==0){
            if(x-1<1 or x-1>n or zb[x-1][y]=='x'){
                d=(d+1)%4;
            }
            else{
                x--;
                ans++;
                if(zb[x][y]==0){
                    ans--;
                }
                zb[x][y]=0;
            }
            yn++;
        }
        k--;
    }
        cout<<ans<<endl;
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                zb[i][j]=0;
            }
        }
        */
    }
    return 0;
}
