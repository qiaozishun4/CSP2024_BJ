#include<bits/stdc++.h>
using namespace std;
char map1[1003][1003];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map1[i][j];
            }
        }
        if(map1[x+1][y]=='.' || map1[x][y+1]=='.' || map1[x-1][y]=='.' || map1[x][y-1]=='.'){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
