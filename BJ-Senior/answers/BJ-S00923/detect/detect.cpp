#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int d[N],v[N],a[N],p[N],n,m,l,V;
bool check(int t,int i){
    int s=v[i]*t+0.5*a[i]*t*t;
    if (s+d[i]==p[m]) return true;
    return false;
}
void MAIN(){
    bool flag1=true,flag2=true;
    cin>>n>>m>>l>>V;
    for (int i=1;i<=n;i++){
        cin>>d[i]>>v[i]>>a[i];
        if (a[i]!=0) flag1=false;
        if (a[i]<=0) flag2=false;
    }
    for (int i=1;i<=m;i++) cin>>p[i];
    sort(p+1,p+m+1);
    if (flag1){
        int ans=0;
        for (int i=1;i<=n;i++){
            if (v[i]>V && d[i]<=p[m]) ans++;
        }
        cout<<ans<<" "<<m-1<<endl;
    }
    else if (flag2){
        int ans=0;
        for (int i=1;i<=n;i++){
            int t;
            for (t=1;t<=1000;t++){
                if (d[i]+v[i]*t+0.5*a[i]*t*t >= p[m]) break;
            }
            double s=v[i]*t+0.5*a[i]*t*t;
            int x;
            if (s == 1.0*((v[i]+a[i]*t)*(v[i]+a[i]*t)-v[i]*v[i])/2/a[i]) x=v[i]+a[i]*t;
            else x=sqrt(v[i]*v[i]+2*a[i]*s);
            if (x>V) ans++;
        }
        cout<<ans<<" "<<m-1<<endl;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--) MAIN();
    return 0;
}
