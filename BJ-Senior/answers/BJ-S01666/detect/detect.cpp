#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        double d[n],v[n],a[n],p[m];
        bool b[m];
        int ans=0;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[j]>=d[i]){
                    if(v[i]+sqrt(2*a[i]*(p[j]-d[i]))>V){
                        ans++;
                        if(a[i]<0) b[j]=1;
                        else b[m-1]=1;
                        break;
                    }
                }
            }
        }
        int ans2=m;
        for(int i=0;i<m;i++){
            if(b[i]==1){
                ans2--;
            }
        }
        cout<<ans<<" "<<ans2<<endl;
    }
}
