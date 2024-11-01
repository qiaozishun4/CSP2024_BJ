#include<bits/stdc++.h>
using namespace std;
int d[1000005],a[100005],v[100005],p[100005];
int T,ans=0;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    for(int i=1;i<=T;i++){
        int n,m,L,V;
        for(int i=1;i=n;i++){
            cin>>d[i];
        }
            for(int i=1;i=n;i++){
            cin>>v[i];
        }
        for(int i=1;i=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }   
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                int vmax=sqrt(v[i]*v[i]+2*a[i]*(L-d[i]));
                if(vmax>V){
                    if(vmax<sqrt(2*a[i]*p[m]+v[i]*v[i]) && p[m]>d[i]){
                        ans++;
                    }
                }
            }
            if(a[i]=0){
                if(v[i]>V && p[m]>d[i]) ans++;
            }
            if(a[i]<0){
                int vmax=x[i];
                if(vmax>V){
                    if(sqrt(2*a[i]*p[1]+v[i]*v[i])>V) ans++;
                }
            }
        }
        cout<<ans<<ans;
    }
    return 0;
}