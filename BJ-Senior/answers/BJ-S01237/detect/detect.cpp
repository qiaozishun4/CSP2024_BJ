#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n[1000010],m[1000010],L[1000010],V[1000010],d[1000010],v[1000010],a[1000010],p[1000010];
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>m[i]>>L[i]>>V[i];
        for(int j=1;j<=n;j++){
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        cout<<L[i]/n[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
