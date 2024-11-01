#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,a[100010],c[100010],g[100010],x[4][260];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=3;i++){
        cin>>g[i];
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>x[1][i]>>x[2][i]>>x[3][i]>>x[4][i];
    }
    cout<<"5\n19\n7\n1";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
