#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,f,x2,y2;
        cin>>n>>m>>k>>x>>y>>f;
        x--;y--;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;
                cin>>c;
                if(c=='.') a[i][j]=0;
                else a[i][j]=1;
            }
        }
        a[x][y]=2;
        while(k--){
            x2=x;y2=y;
            if(f==0) y2=y+1;
            if(f==1) x2=x+1;
            if(f==2) y2=y-1;
            if(f==3) x2=x-1;
            if(x2>=0&&y2>=0&&x2<n&&y2<m){
                if(a[x2][y2]!=1){
                    x=x2;
                    y=y2;
                    a[x][y]=2;
                    continue;
                }
            }
            f=(f+1)%4;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
