#include<iostream>
using namespace std;
int n,m,k,x,y,d;
bool a[1003][1003],vis[1003][1003];
int doing(){
    cin>>n>>m>>k>>x>>y>>d;
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=0;
            char opt;
            cin>>opt;
            a[i][j]=(opt=='x');
        }
    }
    vis[x][y]=1;
    while(k--){
        if(d==0){
            if(a[x][y+1]||y>=m)d=(d+1)%4;
            else y++;
        }
        else if(d==1){
            if(a[x+1][y]||x>=n)d=(d+1)%4;
            else x++;
        }
        else if(d==2){
            if(a[x][y-1]||y<=1)d=(d+1)%4;
            else y--;
        }
        else if(d==3){
            if(a[x-1][y]||x<=1)d=(d+1)%4;
            else x--;
        }
        if(!vis[x][y])ans++,vis[x][y]=1;
    }
    return ans;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<doing()<<'\n';
    }
    return 0;
}