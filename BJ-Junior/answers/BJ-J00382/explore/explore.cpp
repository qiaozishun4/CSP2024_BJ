#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        int a[1010][1010];
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                char c;
                cin>>c;
                if(c=='.'){
                    a[j][l]=1;
                }
                else{
                    a[j][l]=0;
                }
            }
        }
        a[x][y]=2;
        for(int j=1;j<=k;j++){
            if(d==0){
                if(y+1<=m&&a[x][y+1]!=0){
                    y++;
                    a[x][y]=2;
                }
                else{
                    d=1;
                    continue;
                }
            }
            if(d==1){
                if(x+1<=n&&a[x+1][y]!=0){
                    x++;
                    a[x][y]=2;
                }
                else{
                    d=2;
                    continue;
                }
            }
            if(d==2){
                if(y-1>=1&&a[x][y-1]!=0){
                    y--;
                    a[x][y]=2;
                }
                else{
                    d=3;
                    continue;
                }
            }
            if(d==3){
                if(x-1>=1&&a[x-1][y]!=0){
                    x--;
                    a[x][y]=2;
                }
                else{
                    d=0;
                    continue;
                }
            }

        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                if(a[j][l]==2){
                    ans++;
                }
            }
        }

        cout<<ans<<endl;

    }

    return 0;
}
