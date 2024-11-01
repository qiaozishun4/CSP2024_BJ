# include <bits/stdc++.h>

using namespace std;
int t,n,m,k,d,ans,x,y;
char a[1005][1005];
int b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i1=1;i1<=t;i1++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                b[i][j]=0;
            }
        }
        b[x][y]=1;
        for(int i=1;i<=k;i++){
            if(d==0){
                if(y+1>m||y+1<=0||a[x][y+1]!='.'){
                    d=1;
                }
                else{
                    y=y+1;
                    if(b[x][y]==0){
                        ans++;
                        b[x][y]=1;
                    }
                }
            }
            else if(d==1){
                if(x+1>n||x+1<=0||a[x+1][y]!='.'){
                    d=2;
                }
                else{
                    x=x+1;
                    if(b[x][y]==0){
                        ans++;
                        b[x][y]=1;
                    }
                }
            }
            else if(d==2){
                if(y-1>m||y-1<=0||a[x][y-1]!='.'){
                    d=3;
                }
                else{
                    y=y-1;
                    if(b[x][y]==0){
                        ans++;
                        b[x][y]=1;
                    }
                }
            }
            else if(d==3){
                if(x-1>n||x-1<=0||a[x-1][y]!='.'){
                    d=0;
                }
                else{
                    x=x-1;
                    if(b[x][y]==0){
                        ans++;
                        b[x][y]=1;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }



    return 0;
}
