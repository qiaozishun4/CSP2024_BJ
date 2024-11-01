#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[1005][1005];
int dfs(int k,int x,int y,int d,int c){
    if(k==0)
        return c;
    if(d==0){
        if(y+1<=m&&a[x][y+1]=='.'){
            a[x][y+1]=='-';
            dfs(k-1,x,y+1,0,c+1);
        }
        else if(y+1<=m&&a[x][y+1]=='-')dfs(k-1,x,y+1,0,c);
        else{
            int d1=(d+1)%4;
            dfs(k-1,x,y,1,c);
        }
    }
    if(d==1){
        if(x+1<=n&&a[x+1][y]=='.'){
            a[x+1][y]=='-';
            dfs(k-1,x+1,y,1,c+1);
        }
        else if(x+1<=n &&a[x+1][y]=='-')dfs(k-1,x+1,y,1,c);
        else{
            int d1=(d+1)%4;
            dfs(k-1,x,y,2,c);
        }
    }
    if(d==2){
        if(y-1>=1&&a[x][y-1]=='.'){
            a[x][y-1]=='-';
            dfs(k-1,x,y-1,2,c+1);
        }
        else if(y-1>=1&&a[x][y-1]=='-')dfs(k-1,x,y-1,2,c);
        else{
            int d1=(d+1)%4;
            dfs(k-1,x,y,3,c);
        }
    }
    if(d==3){
        if(x-1>=1&&a[x-1][y]=='.'){
            a[x-1][y]=='-';
            dfs(k-1,x-1,y,3,c+1);
        }
        else if(x-1>=1&&a[x-1][y]=='-')dfs(k-1,x-1,y,3,c);
        else{
            int d1=(d+1)%4;
            dfs(k-1,x,y,0,c);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int p;
    cin>>p;
    for(int i=1;i<=p;i++){
        int k,x,y,d;
        bool f=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]!='.')f=0;
            }
        }
        if(f){
            int ans=n*m-(n-2)*(m-2),c=0;
            if(x>1&&y>1&&x<m&&y<n){
                if(d==0){
                    k-=m-x;
                    c+=m-x;
                    x=m;
                }
                else if(d==1){
                    k-=n-y;
                    c+=n-y;
                    y=n;
                }
                else if(d==2){
                    k-=x-1;
                    c+=x-1;
                    x=1;
                }
                else if(d==3){
                    k-=y-1;
                    c+=y-1;
                    y=1;
                }
            }
            if(d==0){
                if(k-3>ans)cout<<ans+c<<endl;
                else{
                    if(k>n+m+n+3)k-=3;
                    else if(k>n+m+2)k-=2;
                    else if(k>n+1)k-=1;
                    cout<<k+c<<endl;
                }
            }
            else if(d==1){
                k-=2*m;
                if(k-3>ans)cout<<ans+c<<endl;
                else{
                    if(k>n+m+n+3)k-=3;
                    else if(k>n+m+2)k-=2;
                    else if(k>n+1)k-=1;
                    cout<<k+c<<endl;
                }
            }
            else if(d==2){
                k-=2;
                if(k-3>ans)cout<<ans+3<<endl;
                else{
                    if(k>n+m+n+3)k-=3;
                    else if(k>n+m+2)k-=2;
                    else if(k>n+1)k-=1;
                    cout<<k+c<<endl;
                }
            }
            else{
                k-=1;
                if(k-3>ans)cout<<ans+c<<endl;
                else{
                    if(k>n+m+n+3)k-=3;
                    else if(k>n+m+2)k-=2;
                    else if(k>n+1)k-=1;
                    cout<<k+c;
                }
            }
        }
        else{
            int ans=dfs(k,x,y,d,0);
            cout<<ans+1<<endl;
        }

    }
    return 0;
}


