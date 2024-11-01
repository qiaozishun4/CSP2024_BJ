#include <bits/stdc++.h>
using namespace std;
double t;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,L,ans=0;
        double V;
        cin>>n>>m>>L>>V;
        double a[n+5],b[n+5],c[n+5],B[m+5];
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]>V)ans++;
        }for(int i=1;i<=m;i++){
            cin>>B[i];
        }for(int i=1;i<=n;i++){
            ans--;
            for(int j=1;j<=m;j++){
                if(a[i]<=B[j]){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" "<<m-1<<endl;
    }fclose(stdin);
    fclose(stdout);

return 0;
}
