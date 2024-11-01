#include<bits/stdc++.h>
using namespace std;
const int MAX=1e3+10;
char a[MAX][MAX];
int dfs(int x,int y,int d,int k,int n,int m){
    if(k==0){
        if(a[x][y]=='.')return 1;
        else return 0;
    }
    if(d==0){
        if(y+1<=0||y+1>=m){
            return dfs(x,y,((d+1)%4),k-1,n,m);
        }else if(a[x][y+1]=='.'){
            return dfs(x,y+1,d,k-1,n,m)+1;
        }else{
            return dfs(x,y,((d+1)%4),k-1,n,m);
        }
    }
    if(d==1){
        if(x+1>=n){
            return dfs(x,y,((d+1)%4),k-1,n,m);
        }
        else if(a[x+1][y]=='.'){
            return dfs(x+1,y,d,k-1,n,m)+1;
        }else{
            return dfs(x,y,((d+1)%4),k-1,n,m);
        }
    }
    if(d==2){
        if(y-1<=0)return dfs(x,y,((d+1)%4),k-1,n,m);
        else if(a[x][y-1]=='.'){
            return dfs(x,y-1,d,k-1,n,m)+1;
        }else{
            return dfs(x,y,((d+1)%4),k-1,n,m);
        }
    }
    if(d==3){
        if(x-1<=0)return dfs(x,y,((d+1)%4),k-1,n,m);
        else if(a[x-1][y]=='.'){
            return dfs(x-1,y,d,k-1,n,m)+1;
        }else{
            return dfs(x,y,((d+1)%4),k-1,n,m);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,x,y,d,nx,ny,nd;
    int t;
    cin>>t;
     while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            string tmp;
            cin>>tmp;
            for(int j=0;j<tmp.size();j++){
                a[i][j+1]=tmp[j];
            }
        }
       cout<<dfs(x,y,d,k,n,m)<<endl;
    }

    return 0;
}
