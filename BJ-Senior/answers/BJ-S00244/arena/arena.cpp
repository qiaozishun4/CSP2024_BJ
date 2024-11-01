#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[200000],k,c[200000];
char s[20][200000];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=m;j++){
        cin>>c[i];
    }
    k=log2(n);
    if(pow(2,k)<n) k++;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=(1<<(k-i))){
            cin>>s[i][j];
        }
    }
    cin>>t;
    while(t--){
        int a1,a2,a3,a4;
        cin>>a1>>a2>>a3>>a4;
    }

    return 0;
}