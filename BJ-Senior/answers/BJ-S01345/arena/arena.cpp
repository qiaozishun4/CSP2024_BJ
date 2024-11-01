#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],c[100005];
int gr[10005][10005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    int k=ceil(log2(n));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=(1<<(k-i));j++){
            cin>>gr[i][j];
        }
    }
    int t;
    cin>>t;
    while(t--){
        int a1,a2,a3,a4;
        cin>>a1>>a2>>a3>>a4;
        cout<<a1+a2+a3+a4<<endl;
    }
    return 0;
}
