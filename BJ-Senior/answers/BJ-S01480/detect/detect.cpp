#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int d[N],v[N],a[N];
int p[N];
long long js(long long cs,long long jsd,long long lc){
    return sqrt(cs*cs+jsd*lc*2);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        bool ta=true;
        bool tb=true;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0) ta=false;
            if(a[i]<0) tb=false;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int ans1=0;
        int ans2=0;
        if(ta){
            for(int i=1;i<=n;i++){
                if(v[i]>V){
                    ans1++;
                }
            }
            if(ans1==0) cout<<ans1<<" "<<n;
            else cout<<ans1<<" "<<n-1;
        }else if(tb){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(d[i]>p[j]) continue;
                    if(js(v[i],a[i],p[j]-d[i])>V){
                        ans1++;
                        break;
                    }
                }
            }
            cout<<ans1<<" "<<n-1;
        }
        cout<<endl;
    }
    return 0;
}
