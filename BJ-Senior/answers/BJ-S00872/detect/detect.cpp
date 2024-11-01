#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        int d[n+1],vt[n+1],a[n+1],p[m+1];
        double time[n+1],place[n+1];
        for(int j=1;j<=n;j++){
            cin>>d[j]>>vt[j]>>a[j];
//            double time;
            if(a[j]==0){
                time[j]=0;
                place[j]=0;
            }
            else{
                time[j]=double(v*v-vt[j]*vt[j])/(2.0*double(a[j]));
                place[j]=double(vt[j])*time[j]+0.5*double(a[j])*time[j]*time[j];
            }
            //place[j]=d[j]+sqrt(double(vt[j])*time[j]+0.5*double(a[j])*time[j]*time[j]);
        }
        int mn=1e9,mx=0;
        for(int j=1;j<=m;j++){
            cin>>p[j];
            mx=max(mx,p[j]);
            mn=min(mn,p[j]);
        }
        int ans1=0;
        for(int j=1;j<=n;j++){
            if((vt[j]>v)&&(d[j]<=mx)&&(a[j]==0)){
                ans1++;
            }
            else if(sqrt(double(vt[j])*double(vt[j])+2.0*double(a[j])*double(mx-d[j]))>v&&a[j]>0&&d[j]<=mx){
                ans1++;
            }
        }
        cout<<ans1<<' ';
        if(ans1!=0){
            cout<<m-1<<'\n';
        }
        else{
            cout<<m<<'\n';
        }
    }
    return 0;
}
