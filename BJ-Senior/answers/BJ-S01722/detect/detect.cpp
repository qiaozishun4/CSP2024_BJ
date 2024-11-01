#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p[100005];
int ovs[100005];

int main(){
    freopen("detect2.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(ovs,0,sizeof(ovs));
        int ans1=0,plc=-1,ans2=0;
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        bool flag=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]) flag=1;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+n+1);
        if(!flag){
            for(int i=1;i<=n;i++){
                if(v[i]>V){
                    ans1++;
                    for(int j=1;j<=m;j++){
                        if(d[i]<p[j]){
                            plc=max(plc,p[j]);
                            break;
                        }
                    }
                }
            }
            for(int i=1;i<=m;i++){
                if(p[i]<plc){
                    ans2++;
                }
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    double x=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
                    if(p[j]>=d[i]&&x>V){
                        ans1++;
                        ovs[j]++;
                        break;
                    }
                }
            }
            for(int i=1;i<=m;i++){
                if(ovs[i]==0) ans2++;
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
    }
    return 0;
}
