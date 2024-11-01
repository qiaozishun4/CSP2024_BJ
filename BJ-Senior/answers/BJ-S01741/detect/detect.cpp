#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    double t,n,m,l,sp,ansa,mp,v[100005],a[100005],d[100005],p[100005];
    cin>> t;
    while(t--){
        ansa = 0;
        mp = 2e9;
        cin>> n >> m >> l >> sp;
        for(int i=1;i<=n;i++){
            cin>> d[i] >> v[i] >> a[i];
        }
        for(int i=1;i<=m;i++){
            cin>> p[i];
            mp = min(mp,p[i]);
        }
        for(int i=1;i<=n;i++){
            if(sp*sp<v[i]+2*a[i]*(d[i]-mp)) ansa++;
        }

        cout<< ansa << ' ' <<m-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}