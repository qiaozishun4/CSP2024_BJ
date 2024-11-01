#include<bits/stdc++.h>
using namespace std;
double t,n,m,l,V,d[100005],v[100005],a[100005],p[100005],ans1,ans2;
bool on[100005],on2[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int j=1;j<=m;j++){
            cin>>p[j];
        }
        for(int i=1;i<=n;i++){
            int x=-1;
            for(int j=1;j<=m;j++){
                if(p[j]<d[i]) continue;
                double tv=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
                if(tv>V){
                    on[i]=1;
                    x=j;
                }
            }
            if(x!=-1){
                on2[x]=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(on[i]) ans1++;
        }
        for(int j=1;j<=m;j++){
            if(on2[j]) ans2++;
        }
        cout<<ans1<<' '<<n-ans2<<endl;
    }
    return 0;
}
