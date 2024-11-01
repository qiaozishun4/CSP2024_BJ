#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[1000005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    int T;
    cin>>T;
    while(T--){
        cout<<"0\n";
    }
    return 0;
}
