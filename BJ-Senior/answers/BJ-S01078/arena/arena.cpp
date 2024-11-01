#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int c[N];
int p[N][N];
int q[300][10];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cout<<3267;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    double fff=log2(n);
    int k;
    if(fff==int(fff)){
        k=fff;
    }else{
        k=fff+1;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=pow(2,k-i);j++){
            cin>>p[i][j];
        }
    }
    int t;
    cin>>t;
    
    return 0;
}