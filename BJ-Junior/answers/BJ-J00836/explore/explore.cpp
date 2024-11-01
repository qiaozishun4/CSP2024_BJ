#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,c,e,ans;
int a[1002][1002],b[1002][1002];
void dfs(int x,int y,int min){
    if(min==k+1){
        return;
    }else{
        if(d==0){
            if(a[x][y+1]==1){
                b[x][y]=1;
                dfs(x,y+1,min+1);
            }else{
                d++;
                dfs(x,y,min+1);
            }
        }else if(d==1){
            if(a[x+1][y]==1){
                b[x][y]=1;
                dfs(x+1,y,min+1);
            }else{
                d++;
                dfs(x,y,min+1);
            }
        }else if(d==2){
            if(a[x][y-1]==1){
                b[x][y]=1;
                dfs(x,y-1,min+1);
            }else{
                d++;
                dfs(x,y,min+1);
            }
        }else if(d==3){
            if(a[x-1][y]==1){
                b[x][y]=1;
                dfs(x-1,y,min+1);
            }else{
                d=0;
                dfs(x,y,min+1);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char v;
                cin>>v;
                if(v=='.'){
                    a[i][j]=1;
                }else if(v=='x'){
                    a[i][j]=-1;
                }
            }
        }
        b[x][y]=1;
        dfs(x,y,0);
        int num=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==1){
                    num++;
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
