#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int t,d[MAXN],u[MAXN],a[MAXN],p[MAXN];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,l,v;
        int cnt=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)cin>>d[i]>>u[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            int t=(v-u[i])*1.0/a[i];
            int s=u[i]*t+0.5*a[i]*t*t+d[i];
            if(p[m]<s)cnt++;
        }cout<<cnt<<" "<<m-cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
