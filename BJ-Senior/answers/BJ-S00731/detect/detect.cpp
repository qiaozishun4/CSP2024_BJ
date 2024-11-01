#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;

    while(t--){
        int ans=0,n,m;
        double l,V;
        cin>>n>>m>>l>>V;
        double d[100005],u[100005],a[100005],p[100005];
        for(int i=0;i<n;i++){
            cin>>d[i]>>u[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]==0&&u[i]>V){
                ans++;
                continue;
            }else if(a[i]==0){
                continue;
            }
            //if(a[i]<0)
            double s=(V*V-(0-u[i])*(0-u[i]))/(2*a[i]);
            for(int j=0;j<=m;j++){
                if(p[j]>=d[i]&&p[j]<=d[i]+s){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" "<<m-2<<endl;
    }

    return 0;
}
