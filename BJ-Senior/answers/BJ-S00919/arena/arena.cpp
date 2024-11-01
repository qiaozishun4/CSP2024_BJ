#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    int n,m,a[100001],c[100001],T,x[100001],K,R,G,y[100001];
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    cin>>K;
    cin>>R;
    cin>>G;
    cin>>T;
    for(int i=1;i<=T;i++) cin>>x[i];
    for(int i=1;i<=T;i++) cout<<y[i]<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
