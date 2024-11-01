#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,v;
struct Q{
    long long d,v,a;
};
Q e[1000005];
long long p[1000005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        long long jsq=0,s;
        long double v1;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>e[i].d>>e[i].v>>e[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(e[i].d<p[m]){
                if(e[i].a!=0){
                    s=p[m]-e[i].d;
                    v1=sqrt(e[i].v*e[i].v+2*e[i].a*s);
                    if(v1>double(v*1.0)){
                        jsq++;
                    }
                }
                else if(e[i].v>v){
                    jsq++;
                }
            }
        }
        cout<<jsq<<" "<<m-1<<endl;
    }
    return 0;
}
