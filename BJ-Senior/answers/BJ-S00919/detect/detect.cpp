#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T,n,m,L,V,d[100001],v[100001],a[100001],p[100001],z,b,s,v1;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++) cin>>d[j]>>v[j]>>a[j];
        for(int j=1;j<=m;j++) cin>>p[j];
    }
    for(int i=1;i<=n;i++){
        s=(V*V-v[i]*v[i])/(2*a[i]);
        v1=sqrt(v[i]*v[i]+2*a[i]*s);
        if(v1>V){
            z++;
            b++;
        }
    }
    cout<<z<<" "<<b;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
