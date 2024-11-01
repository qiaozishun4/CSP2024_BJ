#include<bits/stdc++.h>
using namespace std;
int p[100005],m,n,T,L,V,d[100005],v[100005],a[100005],ans1;//a加速度，v初速，d进入位置，m监控数，n车数，T组数，V限速，p测速位置
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        ans1=0;
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++){
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=1;j<=m;j++){
            cin>>p[j];
        }
        if(a[1]==0){
            for(int j=1;j<=n;j++){
                if(v[j]>V&&d[j]<=p[m])ans1++;
            }
            if(ans1 != 0)cout<<ans1<<' '<<m-1<<endl;
            else cout<<ans1<<' '<<m<<endl;
        }
        else if(a[1]>0){
            for(int j=1;j<=n;j++){
                    if(d[j]<=p[m]){
                        if(sqrt(v[j]*v[j] + 2*a[j]*(p[m]-d[j]))>V)ans1++;
                    }
            }
            if(ans1 != 0)cout<<ans1<<' '<<m-1<<endl;
            else cout<<ans1<<' '<<m<<endl;
        }
        else if(a[1]<0);
    }
    return 0;
}