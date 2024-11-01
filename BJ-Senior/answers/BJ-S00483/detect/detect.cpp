#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d[100010],v[100010],a[100010],p[100010];
int ans1;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        ans1=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            if(d[i]>p[m])continue;
            if(a[i]<0)continue;
            if(a[i]==0){
                if(v[i]>V)ans1++;
            }
            if(a[i]>0){
                int s=p[m]-d[i];
                double sd=sqrt(v[i]*v[i]+2*a[i]*s);
                if(sd>V)ans1++;
            }
        }
        cout<<ans1<<" "<<m-1;
    }
    return 0;
}
