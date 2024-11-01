#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,d[100005],c[100005],a[100005],p[100005],ans;
double s;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)cin>>d[i]>>c[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++){
            if(p[m]>=d[i]){
               s=pow(c[i],2)+(2*a[i]*(p[m]-d[i]));
               if(sqrt(s)>v) ans++;
            }

        }
        cout<<ans<<" "<<(ans==0?m:m-1)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}