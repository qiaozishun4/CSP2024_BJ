#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],c[100001],ra[100001],x[4],k=0,t;
bool ans[50][400001];
char ka[50][200001];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>ra[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    while((1<<k)<n)k++;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=(1<<(k-i));j++){
            cin>>ka[i][j];
        }
    }
    cin>>t;
    while(t--){
        cout<<0<<endl;
    }
    return 0;
}
