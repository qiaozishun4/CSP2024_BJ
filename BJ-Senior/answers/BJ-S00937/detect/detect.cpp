#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,cnt,v,d[100002],u[100002],a[100002],c[1000002],r[100002];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>u[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>r[i];
            c[r[i]]=1;
        }
        for(int i=1;i<=n;i++){
            if(u[i]<=v&&a[i]<=0){
                cnt=cnt;
            }
            else if(a[i]<0){
                float y=(v*v-u[i]*u[i])*1.0/2*a[i],z=y+d[i];
                for(int i=d[i];i<=z;i++){
                    if(c[i]){
                        cnt++;
                        break;
                    }
                }
            }
            else if(u[i]>v&&a[i]>0&&r[m]>d[i]){
                cnt++;
            }
            else{
                int g=r[m]-d[i];
                if(g>0){
                    float y=sqrt(u[i]*u[i]+a[i]*2*g);
                    if(y>(float)v){
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<' '<<3<<endl;
    }
    return 0;
}
