#include <bits/stdc++.h>
using namespace std;
int t;
double cs[500000],as[500000],vs[500000];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;

    while(t--){
        long long ans1=0,truly=0;
        double n,m,l,p,lv;

        cin>>n>>m>>l>>lv;
        for(int i=0;i<n;i++){
            double d,a,v;
            cin>>d>>v>>a;
            if(a==0){
                if(truly==0 || truly==1) truly=1;
                else truly=-1;
                if(v>lv){
                    cs[ans1]=d;
                    ans1+=1;
                }
            }
            else if(a>0){
                if(truly==0 || truly==2) truly=2;
                else truly=-1;
                double f=sqrt(v*v+2*(l-d)*a);
                if(f>lv){
                    vs[ans1]=v;
                    as[ans1]=a;
                    cs[ans1]=d;
                    ans1+=1;
                }
            }
            else truly=-1;

        }

        if(truly==1){
            for(int i=0;i<m;i++) cin>>p;
            for(int i=0;i<ans1;i++) if(cs[i]>p) ans1-=1;
            if(ans1==0) cout<<0<<" "<<m<<endl;
            else cout<<ans1<<" "<<m-1<<endl;
        }
        if(truly==2){
            for(int i=0;i<m;i++) cin>>p;
            for(int i=0;i<ans1;i++) {double f=sqrt(vs[i]*vs[i]+2*(p-cs[i])*as[i]); if(cs[i]>p || f<=lv) ans1-=1;}
            if(ans1==0) cout<<0<<" "<<m<<endl;
            else cout<<ans1<<" "<<m-1<<endl;
        }

    }
    return 0;
}