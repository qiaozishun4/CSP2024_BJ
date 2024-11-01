#include <bits/stdc++.h>

using namespace std;

int  L,V,d[100005],v[100005],a[100005],t;
int p=0,p1,T,n,m,ans=0,pan=0;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int i1=1;i1<=T;i1++){
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]==0){
                pan=1;
            }
            if(a[i]>0){
                pan=2;
            }
        }
        for(int i=0;i<m;i++){
            cin>>p1;
            if(p1>p){
                p=p1;
            }
        }
        if(pan==1){
            for(int i=0;i<n;i++){
                if(d[i]<=p&&v[i]>V){
                    ans++;
                }
            }
            if(ans==0){
                cout<<ans<<" "<<m<<endl;
            }
            else{
                cout<<ans<<" "<<m-1<<endl;
            }
        }
        if(pan==2){
            for(int i=0;i<n;i++){
                if(v[i]>V||d[i]<=p){
                    ans++;
                }
                if(v[i]==V||d[i]<p){
                    ans++;
                }
                if(v[i]<V){
                    double x=(V-v[i])/a[i];
                    if(x*v[i]+0.5*x*a[i]*x+d[i]<p){
                        ans++;
                    }
                }
            }
            if(ans==0){
                cout<<ans<<" "<<m<<endl;
            }
            else{
                cout<<ans<<" "<<m-1<<endl;
            }
        }
    }

    return 0;
}
