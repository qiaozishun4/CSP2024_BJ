#include<bits/stdc++.h>
using namespace std;
double v[100005],a[100005],d[100005];
int p[100005];
int t,n,m,l,V;
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)cin>>p[i];
        sort(p+1,p+m+1);
        int ans=0;//how many people are too fast
        for(int i=1;i<=n;i++){
            double speed=V-1;
            if(a[i]==0)speed=v[i];
            else if(a[i]>0){
                int j=m;
                int s=p[j]-d[i];
                if(s!=0)speed=max(sqrt(1.0*v[i]*v[i]+2*a[i]*s),speed);
                else speed=v[i];
                if(sqrt(1.0*v[i]*v[i]+2*a[i]*s)<=0)break;
            }
            else{
                for(int j=1;j<=m;j++){
                    if(p[j]>=d[i]){
                        int s=p[j]-d[i];
                        if(s!=0)speed=max(sqrt(1.0*v[i]*v[i]+2*a[i]*s),speed);
                        else speed=v[i];
                        break;
                    }
                }
            }
            if(speed>V)ans++;
            else{
                int j=2;
                int s=p[j]-d[i];
            }
        }
        cout<<ans<<" "<<ans;
        cout<<endl;
    }
    return 0;
}
