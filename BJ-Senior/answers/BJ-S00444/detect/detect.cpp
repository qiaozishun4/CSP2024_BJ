#include <bits/stdc++.h>
using namespace std;
int n,m,l,vup,ans1=0;
int d[100005],v[100005],a[100005],p[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans1=0;
        cin>>n>>m>>l>>vup;
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]>vup) flag=1;
            if(v[i]*v[i]+2*a[i]*(l-d[i])>vup*vup) flag=1;
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s=p[j]-d[i];
                if(s<0) continue;
                int b=v[i]*v[i]+2*a[i]*s;
                if(b<=0){
                    continue;
                }
                double vt=sqrt(b);
                if(vt>vup){
                    ans1++;
                    break;
                }
            }
        }
        cout<<ans1<<' '<<m-flag<<"\n";
    }
    return 0;
}
