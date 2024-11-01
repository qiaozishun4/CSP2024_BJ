#include<iostream>
#include<cstdio>
using namespace std;
void dfs(x,y,d,s,c){
    if(s==0){
        cout<<c<<endl;
        return;
    }
    d%=4;
    if(d==0){
        if(x>=1 && x<=n && y+1>=1 && y+1<=m){
            dfs(x,y+1,0,s-1,c+1);
        }else{
            dfs(x,y,d+1,s-1,c+1);
        }
    }else if(d==1){
        if(x+1>=1 && x+1<=n && y>=1 &&y<=m){
            dfs(x+1,y,1,s-1,c+1);
            
        }else{
        
            dfs(x,y,d+1,s-1,c+1);
        }
    }else if(d==2){
        if(x>=1 && x<=n && y-1>=1 &&y-1<=m){
            dfs(x,y-1,1,s-1,c+1);
            
        }else{
        
            dfs(x,y,d+1,s-1,c+1);
        }
    }else if(d==3){
        if(x-1>=1 && x-1<=n && y>=1 &&y<=m){
            dfs(x-1,y,1,s-1,c+1);
            
        }else{
        
            dfs(x,y,d+1,s-1,c+1);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,
    char a[1001][1001];
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,s=0,x0,y0,d0;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(x0,y0,d0,k,0);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}