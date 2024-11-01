#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    for(int i=1;i<=m;i++){
        cin>>a;
    }
    for(int i=1;i<=int(log2(n)+0.9999999);i++){
        cin>>m;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<rand()%100<<'\n';
    }
    return 0;
}
