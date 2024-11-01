#include <bits/stdc++.h>
using namespace std;

int n,m,L,V,p[100005];

struct car{
    int d,v,a,f;
    float t1,t2;
}a[100005];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        bool fA=1,fB=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
            if(a[i].a<0){
                fA=0;
                fB=0;
                a[i].f=1;
                if(a[i].v<=V){
                    a[i].t1=a[i].t2=-1;
                }
                else{
                    a[i].t1=a[i].d;
                    a[i].t2=(V*V-a[i].v*a[i].v)/(a[i].a*2)+a[i].d;
                }
            }
            else if(a[i].a==0){
                a[i].f=2;
                if(a[i].v<=V){
                    a[i].t1=a[i].t2=-1;
                }
                else{
                    a[i].t1=a[i].d;
                    a[i].t2=L;
                }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        //if(fB){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i].t1==-1){
                    continue;
                }
                else if(a[i].a==0 and a[i].d<=p[m] and a[i].d<=p[m]){
                    cnt++;
                }
                else if(a[i].d<=p[m] and sqrt(a[i].v*a[i].v + 2*a[i].a*(p[m]-a[i].d))>V){
                    cnt++;
                }
            }
            cout<<cnt<<" ";
            if(!cnt){
                cout<<m;
            }
            else{
                cout<<m-1;
            }
            cout<<"\n";
        //}
    }
    return 0;
}
