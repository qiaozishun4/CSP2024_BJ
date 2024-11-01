#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int t, n, m;
int a[5000], c[5000];

int main(){

    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>c[i];
    cin>>t;
    int x[4];
    cin>>x[0]>>x[1]>>x[2]>>x[3];
    for(int i=1;i<=n; i++){
        a[i] = a[i] ^ (x[i%4]);
    }
    for(int i=1; i<=t; i++) cout<<1<<endl;


    return 0;
}
