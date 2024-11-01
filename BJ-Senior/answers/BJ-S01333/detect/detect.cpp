#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,d,v,a,p;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++) cin>>d>>v>>a;
        for(int k=1;k<=m;k++) cin>>p;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
