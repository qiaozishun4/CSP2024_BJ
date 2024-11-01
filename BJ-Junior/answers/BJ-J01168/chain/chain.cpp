#include<bits/stdc++.h>
using namespace std;
int a[20005][20005]={};
bool dfs(int n,int ml,int m,int r,int ln,int c,int ls,int cant){
    if(c>r)if(ls==ln)return 1;
    for(int i=1;i<=n;i++){
        if(i==cant)continue;
        for(int j=1;j<=a[i][0];j++){
            if(a[i][j]==ls){
                for(int k=j+1;k-j<=ml&&a[i][k]==a[i][k-1]+1&&k<=a[i][0];k++){
                    if(dfs(n,ml,m,r,ln,c+1,a[i][k],i))return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    int cnt,n,ml,m,r,ln;
    cin>>cnt;
    while(cnt--){
        cin>>n>>ml>>m;
        for(int i=1;i<=n;i++){
            int b;
            cin>>b;
            a[i][0]=b;
            for(int j=1;j<=b;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=m;i++){
            cin>>r>>ln;
            bool qaz=dfs(n,ml,m,r,ln,1,1,0);
            cout<<qaz<<endl;
        }
    }
    return 0;
}
