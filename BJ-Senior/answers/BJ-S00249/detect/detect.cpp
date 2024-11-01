#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    double d[101],v[101],a[101],p[101];
    int T=0;
    cin>>T;
    while(T--){
        int n,m,L,V,k=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++){
            if(v[i]<=3&&a<=0) continue;
            if(v[i]>3&&a>=0){
                k++;
                continue;
            }
            double s=(9-pow(a[i]))/(2*a[i]);
            if(a<0&&v[i]>0)
            for(int j=d[i]+s;j<=n;j++){
                if(j==p[i]){
                    k++;
                    break;
                }
            }
        }
        
        


return 0;
}
