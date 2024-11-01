
#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,k,m,ans=1;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            int s=0;
            if(d==0&&s==0){
                if(y+1<=m&&a[x][y+1]=='.'){
                    y+=1;
                    ans++;
                }else if(y+1<=m&&a[x][y+1]=='x'){
                    d=(d+1)%4;
                    s=1;
                }else{
                    d=(d+1)%4;
                    s=1;
                }
            }
            if(d==1&&s==0){
                if(x+1<=n&&a[x+1][y]=='.'){
                    x+=1;
                    ans++;
                }else if(x+1<=n&&a[x+1][y]=='x'){
                    d=(d+1)%4;
                    s=1;
                }else{
                    d=(d+1)%4;
                    s=1;
                }
            }
            if(d==2&&s==0){
                if(y-1>=1&&a[x][y-1]=='.'){
                    y-=1;
                    ans++;
                }else if(y-1>=1&&a[x][y-1]=='x'){
                    d=(d+1)%4;
                    s=1;
                }else{
                    d=(d+1)%4;
                    s=1;
                }
            }
            if(d==3&&s==0){
                if(x-1>=1&&a[x-1][y]=='.'){
                    x-=1;
                    ans++;
                }else if(x-1>=1&&a[x-1][y]=='x'){
                    d=(d+1)%4;
                    s=1;
                }else{
                    d=(d+1)%4;
                    s=1;
                }
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]='0';
            }
        }
    }
    return 0;
}
